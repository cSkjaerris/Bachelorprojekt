//
// Created by Casper Skjærris on 2019-02-13.
//

#ifndef SIMULATOR_DISCRETEEVENTSIMULATOR_H
#define SIMULATOR_DISCRETEEVENTSIMULATOR_H


#include <map>
#include <queue>
#include <math.h>
#include <random>

#include "JNASimulatorLink.h"

using namespace std;

enum Event{
    Arrival,
    Finished
};

class DiscreteEventSimulator : public SimulatorLink{
private:
    double simulationTime;
    unsigned int seed;
    double rateOfCustomers;
    double rateOfDesk;
    double closeTime;
    bool isDeskAvailable;
    unsigned int served;
    map<double,Event>* eventMapping;
    queue<Event>* deskQueue;
    void reset();
    void arrive();
    void finish();
    void scheduleNextArrival();
    void scheduleFinish();
    double calculateNextArrival();
    double calculateFinish();
public:
    DiscreteEventSimulator(unsigned int seed, double rateOfCustomers, double rateOfDesk, double closeTime);
    ~DiscreteEventSimulator() = default;
    double getTime() override;
    void performOneStepOfSimulation() override;
    void performWholeSimulation() override;
    void setSimulatorForNewSimulation(unsigned int seed) override;
    double rval(int obs) override;
    double rval(string obs) override;
};


#endif //SIMULATOR_DISCRETEEVENTSIMULATOR_H
