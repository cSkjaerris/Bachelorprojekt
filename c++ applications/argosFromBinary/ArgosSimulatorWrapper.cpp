#include "ArgosSimulatorWrapper.h"

argos::CSimulator* cSimulator = NULL;
MultivestaLoopFunctions* loopFunctions = NULL;

ArgosSimulatorWrapper::ArgosSimulatorWrapper() {
    simulator =  &argos::CSimulator::GetInstance();


    argos::CDynamicLoading::LoadAllLibraries();
    isJustCreated = true;
}

double ArgosSimulatorWrapper::getTime() {
    auto simulationSpace = &simulator->GetSpace();
    return simulationSpace->GetSimulationClock();
}

void ArgosSimulatorWrapper::performOneStepOfSimulation() {
    simulator->UpdateSpace();
}

void ArgosSimulatorWrapper::performWholeSimulation() {
    simulator->Execute();
}

void ArgosSimulatorWrapper::setSimulatorForNewSimulation(unsigned int seed, string settingsPath) {
    //If just created set up experiment and initialize it
    if(isJustCreated) {
        simulator->SetExperimentFileName(settingsPath);
        simulator->LoadExperiment();
        isJustCreated = false;
        simulator->SetRandomSeed(seed);
        cSimulator = &CSimulator::GetInstance();
        loopFunctions = &dynamic_cast<MultivestaLoopFunctions&>(cSimulator->GetLoopFunctions());
    } else {
        simulator->Reset(seed);
    }

}

double ArgosSimulatorWrapper::rval(int obs) {
    return 0;
}

double ArgosSimulatorWrapper::rval(string obs) {

    return loopFunctions->GetXCoordinate();
}

ArgosSimulatorWrapper::~ArgosSimulatorWrapper(){
    simulator->Destroy();
    delete simulator;
    argos::CDynamicLoading::UnloadAllLibraries();
}
