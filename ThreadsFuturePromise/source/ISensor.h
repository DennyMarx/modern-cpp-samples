#pragma once


#include <future>
#include "SensorData.h"


class ISensor
{
public:
	virtual void start() = 0;
	virtual std::future<SensorData> run() = 0;
};
