
#include "Algo.h"
#include "Sensor.h"


int main()
{
    Sensor sensor;
    Algo algo;

    algo.init(sensor);
    
    for(auto i=0; i<10; i++)
    {
        sensor.sense();
        algo.run();
    }

    return 0;
}
