//
// Created by Casper Skjærris on 2019-03-17.
//

#ifndef INVENTORYMANAGEMENTSIMULATOR_JNALINK_H
#define INVENTORYMANAGEMENTSIMULATOR_JNALINK_H

#include "SimulatorLink.h"
#include "InventoryManagementSimulator.h"
using namespace std;

SimulatorLink* simulator;

extern "C"{
double getTime();
void performOneStepOfSimulation();
void performWholeSimulation();
void setSimulatorForNewSimulation(int seed, char* settingsPath);
double rval(int obs);
double rvals(char* obs);
}


#endif //INVENTORYMANAGEMENTSIMULATOR_JNALINK_H
