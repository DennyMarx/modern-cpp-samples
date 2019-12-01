#include "Sensor.h"



Sensor::Sensor()
: _active(false)
{
}


Sensor::~Sensor()
{
}


void Sensor::start()
{
	_active = true;
}


std::future<SensorData> Sensor::run()
{
	_sensorData.sensorValue++;
	std::promise<SensorData> mySensorDataPromise;

	if (_active) 
	{
		mySensorDataPromise.set_value(_sensorData);
	}

	return mySensorDataPromise.get_future();
}
