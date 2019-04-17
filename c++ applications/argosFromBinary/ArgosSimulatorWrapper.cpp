#include "ArgosSimulatorWrapper.h"

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
    } else {
        simulator->Reset(seed);
    }

}

double ArgosSimulatorWrapper::rval(int obs) {
    return 0;
}

double ArgosSimulatorWrapper::rval(string obs) {
    /*
    auto loopfunctions = simulator->GetLoopFunctions();
    auto simulationSpace = &simulator->GetSpace();
    auto rootEntities = simulationSpace->GetRootEntityVector();
    auto entity = &simulationSpace->GetEntity("fb0");
    auto robot = (argos::CFootBotEntity*) entity;
    auto embodiment = robot->GetEmbodiedEntity();
    auto anchor = embodiment.GetEnabledAnchors().front();
    auto positionX = (double) anchor->Position.GetX();
     */
    //return positionX;
    return 0;
}

ArgosSimulatorWrapper::~ArgosSimulatorWrapper(){
    simulator->Destroy();
    delete simulator;
    argos::CDynamicLoading::UnloadAllLibraries();
}
