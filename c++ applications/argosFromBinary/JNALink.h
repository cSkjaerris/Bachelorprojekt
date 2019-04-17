//
// Created by Casper Skjærris on 2019-04-03.
//

#ifndef ARGOSFROMBINARY_JNALINK_H
#define ARGOSFROMBINARY_JNALINK_H

#include "ArgosSimulatorWrapper.h"

SimulatorLink* simulator;
bool isSimulatorSetUp = false;

extern "C" {
double getTime();

void performOneStepOfSimulation();

void performWholeSimulation();

void setSimulatorForNewSimulation(unsigned int seed, char* settingsPath);

double rval(int obs);

double rvals(char* obs);
};


#endif //ARGOSFROMBINARY_JNALINK_H
