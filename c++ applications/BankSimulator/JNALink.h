#ifndef JNALINK_LIBRARY_H
#define JNALINK_LIBRARY_H

#include <vector>
#include <iostream>

#include "SimulatorLink.h"
#include "BankSimulator.h"

SimulatorLink* simulator;

extern "C"{
inline double getTime(){return simulator->getTime();}
inline void performOneStepOfSimulation(){simulator->performOneStepOfSimulation();}
inline void performWholeSimulation(){simulator->performWholeSimulation();}
inline void setSimulatorForNewSimulation(int seed, char* settingsPath){
    delete simulator;
    simulator = new BankSimulator(seed,settingsPath);
    simulator->setSimulatorForNewSimulation(seed,string(settingsPath));}
inline double rval(int obs){return simulator->rval(obs);}
inline double rvals(char* obs) {return simulator->rval(string(obs));}
}

#endif