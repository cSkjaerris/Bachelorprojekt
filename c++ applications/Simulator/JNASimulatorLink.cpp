#include "JNASimulatorLink.h"

double getTime(){
    return simulator->getTime();
}

void performOneStepOfSimulation(){
    simulator->performOneStepOfSimulation();
}

void performWholeSimulation(){
    simulator->performWholeSimulation();
}

void setSimulatorForNewSimulation(int seed){
    delete simulator;
    fstream settingsFile;
    settingsFile.open("/Users/casperskjaerris/Documents/cApp/settings.ini");
    if(!settingsFile){
        cerr << "Could not load settings file";
        exit(1);
    }
    string simulatorType;
    settingsFile >> simulatorType;
    double Rc, Rd,closeTime;
    settingsFile >> Rc;
    settingsFile >> Rd;
    settingsFile >> closeTime;
    settingsFile.close();
    simulator = new DiscreteEventSimulator(seed,Rc,Rd,closeTime);
}

double rval(int obs){
    return simulator->rval(obs);
}

double rvals(char* obs){
    return simulator->rval(string(obs));
}