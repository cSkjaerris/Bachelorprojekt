//
// Created by Casper Skjærris on 2019-03-21.
//

#include "JNALink.h"

double getTime(){return simulator->getTime();}
void performOneStepOfSimulation(){simulator->performOneStepOfSimulation();}
void performWholeSimulation(){simulator->performWholeSimulation();}
void setSimulatorForNewSimulation(int seed, char* settingsPath){
    delete simulator;
    simulator = new SpikeWrapper(seed,settingsPath);
    simulator->setSimulatorForNewSimulation(seed,string(settingsPath));}
double rval(int obs){return simulator->rval(obs);}
double rvals(char* obs) {return simulator->rval(string(obs));}