#pragma once

#include "ISensor.h"

class Sensor : public ISensor
{
public:
	Sensor();
	~Sensor();

	// Inherited via ISensor
	virtual void start() override;

	// Inherited via ISensor
	virtual std::future<SensorData> run() override;

protected:
	bool _active = false;
	SensorData _sensorData;



};

