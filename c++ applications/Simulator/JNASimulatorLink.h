#ifndef SIMULATOR_LIBRARY_H
#define SIMULATOR_LIBRARY_H

#include <iostream>
using namespace std;

extern "C"{
    double getTime();
    void performOneStepOfSimulation();
    void performWholeSimulation();
    void setSimulatorForNewSimulation(int seed);
    double rval(int obs);
    double rvals(char* obs);
}

class SimulatorLink{
public:
    virtual double getTime() = 0;
    virtual void performOneStepOfSimulation() = 0;
    virtual void performWholeSimulation() = 0;
    virtual void setSimulatorForNewSimulation(unsigned int seed) = 0;
    virtual double rval(int obs) = 0;
    virtual double  rval(string obs) = 0;
};
#endif