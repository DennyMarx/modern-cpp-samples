#include <future>
#include <iostream>
#include <thread>
#include <chrono>

#include "Sensor.h"

static std::future<SensorData> _sensorDataFuture;
static volatile bool _dataAvailable = false;
static volatile bool _done = false;


void sensorThreadFunc() 
{
	_done = false;

	// sensor test
	Sensor mySensor;
	mySensor.start();

	for (int i = 0; i < 10; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::future<SensorData> sensorDataFuture = mySensor.run();
		_sensorDataFuture = std::move(sensorDataFuture);
		_dataAvailable = true;
	}
	
	_done = true;
}


void algoThreadFunc()
{
	// consume the sensor data
	while (!_done)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		if (_dataAvailable)
		{
			std::cout << "Sensor Result: " << _sensorDataFuture.get().sensorValue << std::endl;
			_dataAvailable = false;
		}
	}
}



int main() {
	
	std::thread sensorThread(&sensorThreadFunc);
	std::thread algoThread(&algoThreadFunc);

	sensorThread.join();
	algoThread.join();

	return 0;
}
