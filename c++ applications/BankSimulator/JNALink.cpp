//
// Created by Casper Skjærris on 2019-03-17.
//

#include "JNALink.h"

double getTime() {
    return simulator->getTime();
}

void performOneStepOfSimulation() {
    simulator->performOneStepOfSimulation();
}

void performWholeSimulation() {
    simulator->performWholeSimulation();
}

void setSimulatorForNewSimulation(int seed, char *settingsPath) {
    delete simulator;
    simulator = new BankSimulator(seed,string(settingsPath));
}

double rval(int obs) {
    return simulator->rval(obs);
}

double rvals(char* obs) {
    return simulator->rval(obs);
}
