#include "Algo.h"

#include <iostream>



void Algo::init(ISensorCallback& iSensor)
{
    // add lambda function as functor
    // capture to increment member
    iSensor.addObserver([&](){ _numCallbacks++; });
}

void Algo::run()
{
    std::cout << "algo::run: number of callbacks: " << _numCallbacks << std::endl;
}
