#include "SpikeWrapper.h"



SpikeWrapper::SpikeWrapper(unsigned int seed, string settingsPath) {
    sim = make_shared<spsim::Gillespie>();

}

double SpikeWrapper::getTime() {
    return 0;
}

void SpikeWrapper::performOneStepOfSimulation() {

}

void SpikeWrapper::performWholeSimulation() {

}

void SpikeWrapper::setSimulatorForNewSimulation(unsigned int seed, string settingsPath) {

}

double SpikeWrapper::rval(int obs) {
    return 0;
}

double SpikeWrapper::rval(string obs) {
    return 0;
}