//
// Created by Casper Skjærris on 2019-02-13.
//

#include "DiscreteEventSimulator.h"

DiscreteEventSimulator::DiscreteEventSimulator(unsigned int seed, double rateOfCustomers, double rateOfDesk, double closeTime) {
    this->seed = seed;
    this->rateOfCustomers = rateOfCustomers;
    this->rateOfDesk = rateOfDesk;
    this->closeTime = closeTime;
    srand(this->seed);
    reset();
}

void DiscreteEventSimulator::arrive(){
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
    }
    if(deskQueue->empty()){
        isDeskAvailable = true;
    }
}

double DiscreteEventSimulator::getTime() {
    return simulationTime;
}

void DiscreteEventSimulator::performOneStepOfSimulation() {
    if(simulationTime < closeTime){
        for(auto const& [key,val] : *this->eventMapping){
            simulationTime = key;
            if(val == Arrival){
                arrive();
            } else{
                finish();
            }
            break;
        }
        eventMapping->erase(simulationTime);
    }
}

void DiscreteEventSimulator::performWholeSimulation() {
    while(simulationTime < closeTime)
        performOneStepOfSimulation();
}

void DiscreteEventSimulator::setSimulatorForNewSimulation(unsigned int seed) {
    this->seed = seed;
    srand(seed);
    reset();
}

double DiscreteEventSimulator::rval(int obs) {
    return deskQueue->size();
}

double DiscreteEventSimulator::rval(string obs) {
    return served;
}

double DiscreteEventSimulator::calculateFinish() {
    double ran = rand()/double(RAND_MAX);
    return (-log(ran))/rateOfDesk;
}

double DiscreteEventSimulator::calculateNextArrival() {
    double ran = rand()/double(RAND_MAX);
    return (-log(ran))/rateOfCustomers;
}

void DiscreteEventSimulator::scheduleNextArrival() {
    double nextArrivalTime = calculateNextArrival();
    pair<double,Event> nextArrival = pair(nextArrivalTime+simulationTime,Arrival);
    this->eventMapping->insert(nextArrival);
}

void DiscreteEventSimulator::scheduleFinish() {
    double finishTime = calculateFinish();
    pair<double,Event> finish = pair(finishTime+simulationTime,Finished);
    this->eventMapping->insert(finish);
}

void DiscreteEventSimulator::reset() {
    this->deskQueue = new queue<Event>;
    this->eventMapping = new map<double,Event>;
    this->served = 0;
    this->simulationTime = 0;
    this->isDeskAvailable = true;
    pair<double,Event> firstEvent = pair(0,Arrival);
    this->eventMapping->insert(firstEvent);
}


