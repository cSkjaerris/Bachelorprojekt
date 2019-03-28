#ifndef SPIKE_LIBRARY_H
#define SPIKE_LIBRARY_H

#include <iostream>

#include "SimulatorLink.h"
#include "spsim/stochastic/gillespie.h"

using namespace std;

class SpikeWrapper : public SimulatorLink {
private:
    shared_ptr<spsim::Gillespie> sim;
    unsigned long lSeed;
public:
    SpikeWrapper(unsigned int seed, string settingsPath);

    ~SpikeWrapper() = default;

    double getTime() override;

    void performOneStepOfSimulation() override;

    void performWholeSimulation() override;

    void setSimulatorForNewSimulation(unsigned int seed, string settingsPath) override;

    double rval(int obs) override;

    double rval(string obs) override;
};


#endif