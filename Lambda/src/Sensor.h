#pragma once

#include "ISensor.h"
#include "ISensorCallback.h"

#include <functional>
#include <vector>


class Sensor : public ISensor, public ISensorCallback
{
public:
	Sensor();
	~Sensor();

	void sense() override; 
	void addObserver(std::function<void()> callback) override;
	
protected:
	std::vector<std::function<void()>> _eventHandlers;
};

