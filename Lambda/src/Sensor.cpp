#include "Sensor.h"



Sensor::Sensor()
{
}


Sensor::~Sensor()
{
}


void Sensor::sense()
{
	// iterate and execute event handler functors
	for(auto it=_eventHandlers.begin(); it!=_eventHandlers.end(); it++)
	{
		(*it)();
	}
} 


void Sensor::addObserver(std::function<void()> callback)
{
	_eventHandlers.push_back(callback);
}

