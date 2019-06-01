#ifndef BANKSIMULATOR_LIBRARY_H
#define BANKSIMULATOR_LIBRARY_H

#include <map>
#include <queue>
#include <math.h>
#include <random>
#include <fstream>

#include "SimulatorLink.h"

using namespace std;

enum Event{
    Arrival,
    Finished
};

class BankSimulator : public SimulatorLink{
private:
    double simulationTime;
    unsigned int seed;
    double rateOfCustomers;
    double rateOfDesk;
    double closeTime;
    bool isDeskAvailable;
    int arrivals;
    default_random_engine generator;
    uniform_real_distribution<double> uniform0To1;
    unsigned int served;
    map<double,Event>* eventMapping;
    queue<Event>* deskQueue;
    void arrive();
    void finish();
    void scheduleNextArrival();
    void scheduleFinish();
    double calculateNextExponential(double rate);
public:
    BankSimulator(unsigned int seed, string settingsPath);
    ~BankSimulator() = default;
    double getTime() override;
    void performSimulationStep();
    void performSimulation();
    void reset(unsigned int seed, string settingsPath);
    void performOneStepOfSimulation() override;
    void performWholeSimulation() override;
    void setSimulatorForNewSimulation(unsigned int seed, string settingsPath) override;
    double rval(int obs) override;
    double rval(string obs) override;

};


#endif