#include "BankSimulator.h"

BankSimulator::BankSimulator(unsigned int seed, string settingsPath) {
    uniform0To1 = uniform_real_distribution(0.0,1.0);
    reset(seed, settingsPath);
}

void BankSimulator::arrive(){
    arrivals++;
    if(simulationTime < closeTime){
        scheduleNextArrival();
    }
    //scheduleFinish(); //Only uncomment if desk should be independent
    if(isDeskAvailable){
        scheduleFinish();
        isDeskAvailable = false;
    } else{
        deskQueue->push(Arrival);
    }
}

void BankSimulator::finish(){
    served++;
    if(!deskQueue->empty()){
        deskQueue->pop();
        scheduleFinish();
    } else{
        isDeskAvailable = true;
    }
}

double BankSimulator::getTime() {
    return simulationTime;
}

void BankSimulator::performSimulationStep() {
    auto pair = eventMapping->begin();
    simulationTime = pair->first;
    if(pair->second == Arrival){
        arrive();
    } else{
        finish();
    }
    eventMapping->erase(simulationTime);
}

void BankSimulator::performSimulation() {
    while(!eventMapping->empty())
        performSimulationStep();
}

void BankSimulator::performOneStepOfSimulation() {
    performSimulationStep();
}

void BankSimulator::performWholeSimulation() {
    performSimulation();
}

double BankSimulator::rval(int obs) {
    return 0;
}

double BankSimulator::rval(string obs) {
    if(obs == "served")
        return served;
    if(obs == "queueSize")
        return deskQueue->size();
    if(obs == "hasArrived")
        return arrivals;
    return 0; //Default case
}

void BankSimulator::scheduleNextArrival() {
    double nextArrivalTime = calculateNextExponential(rateOfCustomers);
    pair<double,Event> nextArrival = pair(nextArrivalTime+simulationTime,Arrival);
    eventMapping->insert(nextArrival);
}

void BankSimulator::scheduleFinish() {
    double finishTime = calculateNextExponential(rateOfDesk);
    pair<double,Event> finish = pair(finishTime+simulationTime,Finished);
    eventMapping->insert(finish);
}

void BankSimulator::reset(unsigned int seed, string settingsPath) {
    deskQueue = new queue<Event>();
    eventMapping = new map<double,Event>();
    served = 0;
    arrivals=0;
    simulationTime = 0;
    isDeskAvailable = true;
    this->seed = seed;
    generator = default_random_engine(seed);

    double rateOfCustomers, rateOfDesk, closeTime;
    fstream settingsFile;
    settingsFile.open(settingsPath);

    if(!settingsFile){
        cerr << "Could not load settings file";
        exit(1);
    }

    settingsFile >> rateOfCustomers;
    settingsFile >> rateOfDesk;
    settingsFile >> closeTime;
    settingsFile.close();
    this->rateOfCustomers = rateOfCustomers;
    this->rateOfDesk = rateOfDesk;
    this->closeTime = closeTime;
    double firstArrival = calculateNextExponential(rateOfCustomers);
    pair<double,Event> firstEvent = pair(firstArrival,Arrival);
    eventMapping->insert(firstEvent);
}

double BankSimulator::calculateNextExponential(double rate) {
    double ran = uniform0To1(generator);
    return (-log(ran))/rate;
}

void BankSimulator::setSimulatorForNewSimulation(unsigned int seed, string settingsPath) {
    reset(seed, settingsPath);
}
