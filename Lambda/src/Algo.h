#pragma once

#include "IAlgo.h"
#include "ISensorCallback.h"


class Algo : public IAlgo
{
    public:
        void run() override;
        void init(ISensorCallback& iSensor) override;

    private:
        int _numCallbacks = 0;
};
