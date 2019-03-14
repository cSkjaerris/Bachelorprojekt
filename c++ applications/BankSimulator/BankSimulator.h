#ifndef BANKSIMULATOR_LIBRARY_H
#define BANKSIMULATOR_LIBRARY_H

#include <map>
#include <queue>
#include <math.h>
#include <random>

#include

using namespace std;

enum Event{
    Arrival,
    Finished
};

class BankSimulator{
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
    double calculateNextExponential(double rate);
public:
    BankSimulator(unsigned int seed, double rateOfCustomers, double rateOfDesk, double closeTime);
    ~BankSimulator() = default;
    double getTime();
    void performOneStepOfSimulation();
    void performWholeSimulation();
    void setSimulatorForNewSimulation(unsigned int seed);
    double rval(int obs);
    double rval(string obs);
};


#endif