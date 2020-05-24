#pragma once

#include "ISensorCallback.h"

// interface class for Algo
class IAlgo
{
    public:
        virtual void run() = 0;
        virtual void init(ISensorCallback& iSensor) = 0;
};
