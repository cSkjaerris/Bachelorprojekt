//
// Created by Casper Skjærris on 2019-04-03.
//

#include "JNALink.h"

double getTime(){
    return simulator->getTime();
}

void performOneStepOfSimulation(){
    simulator->performOneStepOfSimulation();
}

void performWholeSimulation(){
    simulator->performWholeSimulation();
}

void setSimulatorForNewSimulation(unsigned int seed, char* settingsPath){
    if(!isSimulatorSetUp) {
        simulator = new ArgosSimulatorWrapper();
        isSimulatorSetUp = true;
    }
    simulator->setSimulatorForNewSimulation(seed, std::string(settingsPath));
}

double rval(int obs){
    return simulator->rval(obs);
}

double rvals(char* obs){
    return simulator->rval(string(obs));
}