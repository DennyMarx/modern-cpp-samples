#include <future>
#include <iostream>
#include <thread>
#include <chrono>

#include "Sensor.h"

// future for data communication on-between threads
static std::future<SensorData> _sensorDataFuture;

// promise and future to signal in-between threads
static std::promise<void> _donePromise;
static std::future<void> _doneFuture(_donePromise.get_future());


void sensorThreadFunc() 
{
	// sensor test
	Sensor mySensor;
	mySensor.start();

	for (int i = 0; i < 10; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::future<SensorData> sensorDataFuture = mySensor.run();
		_sensorDataFuture = std::move(sensorDataFuture);
	}
	
	// signal done
	_donePromise.set_value();
}


void algoThreadFunc()
{
	std::future_status _done = _doneFuture.wait_for(std::chrono::milliseconds(1));

	// consume the sensor data as long as _done was not signaled
	while (_done != std::future_status::ready)
	{
		// poll for new sensor data every 500ms
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		bool isSensorDataFutureValid = _sensorDataFuture.valid();
		
		if (isSensorDataFutureValid)
		{
			std::cout << "Sensor Result: " << _sensorDataFuture.get().sensorValue << std::endl;
		}
		else
		{
			std::cout << "Sensor data not ready" << std::endl;
		}
		
		_done = _doneFuture.wait_for(std::chrono::milliseconds(1));
	}

	std::cout << "Sensor is done" << std::endl;
}



int main() {
	
	std::thread sensorThread(&sensorThreadFunc);
	std::thread algoThread(&algoThreadFunc);

	sensorThread.join();
	algoThread.join();

	return 0;
}
