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
void setSimulatorForNewSimulation(int seed, char* settingsPath){
    simulator->setSimulatorForNewSimulation(seed,string(settingsPath));
}
double rval(int obs){
    return simulator->rval(obs);
}
double rvals(char* obs){
    return simulator->rval(string(obs));
}

void registerSimulator(SimulatorLink* sim){
    delete simulator;
    simulator = sim;
}