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
    cout << "Seed: "<< this->seed << endl ;
    cout << "Rate of customers: " << this->rateOfCustomers << endl;
    cout << "Rate of desk: " << this->rateOfDesk << endl;
    cout << "Close time: " << this->closeTime << endl;
}

void DiscreteEventSimulator::arrive(){
    cout << "New customer arrived" << endl;
    if(simulationTime < closeTime){
        scheduleNextArrival();
    }
    if(isDeskAvailable){
        scheduleFinish();
        isDeskAvailable = false;
    } else{
        deskQueue.push(Arrival);
    }
}
void DiscreteEventSimulator::finish(){
    cout << "Customer finished" << endl;
    served++;
    if(!deskQueue.empty()){
        deskQueue.pop();
    }
    if(deskQueue.empty()){
        isDeskAvailable = true;
    }
}

double DiscreteEventSimulator::getTime() {
    return simulationTime;
}

void DiscreteEventSimulator::performOneStepOfSimulation() {
    if(simulationTime < closeTime){
        for(auto const& [key,val] : eventMapping){
            cout << "Map first element [" <<key <<", " << val <<"]" <<endl;
            simulationTime = key;
            if(val == Arrival){
                arrive();
            } else{
                finish();
            }
            break;
        }
        eventMapping.erase(simulationTime);
    }
    cout << "Map first element" <<endl;
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
    return deskQueue.size();
}

double DiscreteEventSimulator::rval(string obs) {
    return served;
}

double DiscreteEventSimulator::calculateFinish() {
    double ran = rand()/double(RAND_MAX);
    cout << "random number: " << ran << endl;
    return (-log(ran))/rateOfDesk;
}

double DiscreteEventSimulator::calculateNextArrival() {
    double ran = rand()/double(RAND_MAX);
    cout << "random number: " << ran << endl;
    double ret = (-log(ran))/rateOfCustomers;
    cout << "exponential distribution number is: " << ret << endl;
    return (-log(ran))/rateOfCustomers;
}

void DiscreteEventSimulator::scheduleNextArrival() {
    double nextArrivalTime = calculateNextArrival();
    cout << "Next arrival = " << nextArrivalTime << " + " << simulationTime << " = " << nextArrivalTime+simulationTime << endl;
    pair<double,Event> nextArrival = pair(nextArrivalTime+simulationTime,Arrival);
    eventMapping.insert(nextArrival);
}

void DiscreteEventSimulator::scheduleFinish() {
    double finishTime = calculateFinish();
    cout << "Next finish calculated to " << finishTime+simulationTime << endl;
    pair<double,Event> finish = pair(finishTime+simulationTime,Finished);
    eventMapping.insert(finish);
}

void DiscreteEventSimulator::reset() {
    deskQueue = queue<Event>();
    eventMapping = map<double,Event>();
    served = 0;
    simulationTime = 0;
    isDeskAvailable = true;
    pair<double,Event> firstEvent = pair(0,Arrival);
    eventMapping.insert(firstEvent);
}




