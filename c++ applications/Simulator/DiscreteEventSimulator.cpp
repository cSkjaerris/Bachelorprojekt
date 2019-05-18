//
// Created by Casper Skjærris on 2019-02-13.
//

#include "DiscreteEventSimulator.h"

DiscreteEventSimulator::DiscreteEventSimulator(unsigned int seed, double rateOfCustomers, double rateOfDesk, double closeTime) {
    this->seed = seed;
    this->rateOfCustomers = rateOfCustomers;
    this->rateOfDesk = rateOfDesk;
    this->closeTime = closeTime;
    reset();
}

void DiscreteEventSimulator::arrive(){
    arrived++;
    if(simulationTime < closeTime){
        scheduleNextArrival();
    }
    if(isDeskAvailable){
        scheduleFinish();
        isDeskAvailable = false;
    } else{
        deskQueue->push(Arrival);
    }
}
void DiscreteEventSimulator::finish(){
    served++;
    if(!deskQueue->empty()){
        deskQueue->pop();
        scheduleFinish();
    } else{
        isDeskAvailable = true;
    }
}

double DiscreteEventSimulator::getTime() {
    return simulationTime;
}

void DiscreteEventSimulator::performOneStepOfSimulation() {
    auto pair = eventMapping->begin();
    simulationTime = pair->first;
    if(pair->second == Arrival){
        arrive();
    } else{
        finish();
    }
    eventMapping->erase(simulationTime);
}

void DiscreteEventSimulator::performWholeSimulation() {
    while(!eventMapping->empty())
        performOneStepOfSimulation();
}

void DiscreteEventSimulator::setSimulatorForNewSimulation(unsigned int seed) {
    this->seed = seed;
    reset();
}

double DiscreteEventSimulator::rval(int obs) {
    return 0;
}

double DiscreteEventSimulator::rval(string obs) {
    if(obs == "served")
        return served;
    if(obs == "queueSize")
        return deskQueue->size();
    if(obs == "hasArrived"){
        return arrived;
    }
    return 0; //Default case
}

void DiscreteEventSimulator::scheduleNextArrival() {
    double nextArrivalTime = calculateNextExponential(rateOfCustomers);
    pair<double,Event> nextArrival = pair(nextArrivalTime+simulationTime,Arrival);
    eventMapping->insert(nextArrival);
}

void DiscreteEventSimulator::scheduleFinish() {
    double finishTime = calculateNextExponential(rateOfDesk);
    pair<double,Event> finish = pair(finishTime+simulationTime,Finished);
    eventMapping->insert(finish);
}

void DiscreteEventSimulator::reset() {
    deskQueue = new queue<Event>();
    eventMapping = new map<double,Event>();
    served = 0;
    simulationTime = 0;
    isDeskAvailable = true;
    arrived = 0;
    srand(this->seed);
    double firstArrival = calculateNextExponential(rateOfCustomers);
    pair<double,Event> firstEvent = pair(firstArrival,Arrival);
    eventMapping->insert(firstEvent);
}

double DiscreteEventSimulator::calculateNextExponential(double rate) {
    double ran = rand()/double(RAND_MAX);
    return (-log(ran))/rate;
}




