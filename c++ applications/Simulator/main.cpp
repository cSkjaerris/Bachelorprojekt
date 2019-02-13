//
// Created by Casper Skjærris on 2019-02-13.
//

#include <iostream>
#include "DiscreteEventSimulator.h"

int main(){
    DiscreteEventSimulator simulator = DiscreteEventSimulator(123,1.0/10,1.0/15,1000);
    for(int i = 0; i<20;i++){
        simulator.performOneStepOfSimulation();
        if(i==5){
            cout << "After 5 steps queueSize = " << simulator.rval(0) << " and served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
        }
        if(i==10){
            cout << "After 10 steps queueSize = " << simulator.rval(0) << " and served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
        }
        if(i==15){
            cout << "After 15 steps queueSize = " << simulator.rval(0) << " and served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
        }
    }
    cout << "final served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
    simulator.setSimulatorForNewSimulation(123);
    cout << "Next round (should be the same)" << endl;
    for(int i = 0; i<20;i++){
        simulator.performOneStepOfSimulation();
        if(i==5){
            cout << "After 5 steps queueSize = " << simulator.rval(0) << " and served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
        }
        if(i==10){
            cout << "After 10 steps queueSize = " << simulator.rval(0) << " and served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
        }
        if(i==15){
            cout << "After 15 steps queueSize = " << simulator.rval(0) << " and served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
        }
    }
    cout << "final served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
    simulator.setSimulatorForNewSimulation(345678);
    cout << "Trying new seed" << endl;
    for(int i = 0; i<20;i++){
        simulator.performOneStepOfSimulation();
        if(i==5){
            cout << "After 5 steps queueSize = " << simulator.rval(0) << " and served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
        }
        if(i==10){
            cout << "After 10 steps queueSize = " << simulator.rval(0) << " and served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
        }
        if(i==15){
            cout << "After 15 steps queueSize = " << simulator.rval(0) << " and served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
        }
    }
    cout << "final served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
    simulator.setSimulatorForNewSimulation(987654321);
    cout << "Running to the end now. New instance" << endl;
    simulator.performWholeSimulation();
    cout << "final served is " << simulator.rval("") << " .Time is " << simulator.getTime() << endl;
}