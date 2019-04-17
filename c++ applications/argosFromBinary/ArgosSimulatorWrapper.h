#ifndef ARGOSFROMBINARY_ARGOSSIMULATORWRAPPER_H
#define ARGOSFROMBINARY_ARGOSSIMULATORWRAPPER_H

#include "SimulatorLink.h"
#include "argos3/core/simulator/simulator.h"
#include "argos3/core/utility/plugins/dynamic_loading.h"
#include "argos3/core/simulator/space/space.h"
#include "argos3/plugins/robots/foot-bot/simulator/footbot_entity.h"

class ArgosSimulatorWrapper : public SimulatorLink {
private:
    argos::CSimulator* simulator;
    bool isJustCreated;
public:
    ArgosSimulatorWrapper();
    ~ArgosSimulatorWrapper();
    double getTime() override;

    void performOneStepOfSimulation() override;

    void performWholeSimulation() override;

    void setSimulatorForNewSimulation(unsigned int seed, std::string settingsPath) override;

    double rval(int obs) override;

    double rval(std::string obs) override;
};

#endif