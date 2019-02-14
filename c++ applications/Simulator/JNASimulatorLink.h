#ifndef SIMULATOR_LIBRARY_H
#define SIMULATOR_LIBRARY_H

#include <iostream>
#include <fstream>

#include "SimulatorLink.h"
#include "DiscreteEventSimulator.h"

using namespace std;

SimulatorLink* simulator;

extern "C"{
double getTime();
void performOneStepOfSimulation();
void performWholeSimulation();
void setSimulatorForNewSimulation(int seed);
double rval(int obs);
double rvals(char* obs);
}


#endif