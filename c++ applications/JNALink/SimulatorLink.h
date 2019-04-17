//
// Created by Casper Skjærris on 2019-03-11.
//

#ifndef JNALINK_SIMULATORLINK_H
#define JNALINK_SIMULATORLINK_H

using namespace std;

#include <iostream>

class SimulatorLink{
public:
    virtual ~SimulatorLink() = default;
    virtual double getTime() = 0;
    virtual void performOneStepOfSimulation() = 0;
    virtual void performWholeSimulation() = 0;
    virtual void setSimulatorForNewSimulation(unsigned int seed, string settingsPath) = 0;
    virtual double rval(int obs) = 0;
    virtual double rval(string obs) = 0;

};


#endif //JNALINK_SIMULATORLINK_H
