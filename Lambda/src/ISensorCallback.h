
#pragma once

#include <functional>


class ISensorCallback
{
public:
    // register to the sensor and provide a callback functor
	virtual void addObserver(std::function<void()> callback) = 0;
};
