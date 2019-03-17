//
// Created by Casper Skjærris on 2019-03-17.
//

#ifndef BANKSIMULATOR_JNALINK_H
#define BANKSIMULATOR_JNALINK_H

#include "BankSimulator.h"
using namespace std;

//SimulatorLink* simulator;
BankSimulator* simulator;

extern "C"{
double getTime();
void performOneStepOfSimulation();
void performWholeSimulation();
void setSimulatorForNewSimulation(int seed, char* settingsPath);
double rval(int obs);
double rvals(char* obs);
}


#endif //BANKSIMULATOR_JNALINK_H
