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
	std::promise<SensorData> mySensorDataPromise;

	if (_active) 
	{
		_sensorData.sensorValue++;
	}

	mySensorDataPromise.set_value(_sensorData);
	return mySensorDataPromise.get_future();
}
