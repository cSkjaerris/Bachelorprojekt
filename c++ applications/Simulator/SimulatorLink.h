//
// Created by Casper Skjærris on 2019-02-14.
//

#ifndef SIMULATOR_SIMULATORLINK_H
#define SIMULATOR_SIMULATORLINK_H

#include <iostream>

using namespace std;

class SimulatorLink{
public:
    virtual double getTime() = 0;
    virtual void performOneStepOfSimulation() = 0;
    virtual void performWholeSimulation() = 0;
    virtual void setSimulatorForNewSimulation(unsigned int seed) = 0;
    virtual double rval(int obs) = 0;
    virtual double rval(string obs) = 0;
};



#endif //SIMULATOR_SIMULATORLINK_H
