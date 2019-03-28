//
// Created by Casper Skjærris on 2019-03-21.
//

#ifndef SPIKE_JNALINK_H
#define SPIKE_JNALINK_H

#include "SimulatorLink.h"
#include "SpikeWrapper.h"

SimulatorLink* simulator;

extern "C"{
double getTime();
void performOneStepOfSimulation();
void performWholeSimulation();
void setSimulatorForNewSimulation(int seed, char* settingsPath);
double rval(int obs);
double rvals(char* obs);
}


#endif //SPIKE_JNALINK_H
