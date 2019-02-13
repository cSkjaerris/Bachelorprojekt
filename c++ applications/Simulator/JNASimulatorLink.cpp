#include "JNASimulatorLink.h"

double getTime(){
    return 0;
}

void performOneStepOfSimulation(){
    cout << "One step of simulation done" << endl;
}

void performWholeSimulation(){
    cout << "Whole simulation done" << endl;
}

void setSimulatorForNewSimulation(int seed){
    cout << "Simulator set with seed: " << seed << endl;
}

double rval(int obs){
    return 1;
}

double rvals(char* obs){
    return 2;
}