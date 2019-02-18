//
// Created by Casper Skjærris on 2019-02-13.
//

#include <iostream>
#include <fstream>

#include "DiscreteEventSimulator.h"
#include "JNASimulatorLink.h"

using namespace std;

int main() {
    string empty = "";
    char* e = new char[empty.length() +1];
    strcpy(e, empty.c_str());
    for (int j = 0; j < 2; j++) {
        setSimulatorForNewSimulation(123);
        for (int i = 0; i < 20; i++) {
            performOneStepOfSimulation();
            if (i == 5) {
                cout << "After 5 steps queueSize = " << rval(0) << " and served is " << rvals(e) << " .Time is "
                     << getTime() << endl;
            }
            if (i == 10) {
                cout << "After 10 steps queueSize = " << rval(0) << " and served is " << rvals(e) << " .Time is "
                     << getTime() << endl;
            }
            if (i == 15) {
                cout << "After 15 steps queueSize = " << rval(0) << " and served is " << rvals(e) << " .Time is "
                     << getTime() << endl;
            }
        }
        cout << "final served is " << rvals(e) << " .Time is " << getTime() << endl;
        cout << "Trying again with same seed" << endl;
    }
    setSimulatorForNewSimulation(345678);
    cout << "Trying new seed" << endl;
    for (int i = 0; i < 20; i++) {
        performOneStepOfSimulation();
        if (i == 5) {
            cout << "After 5 steps queueSize = " << rval(0) << " and served is " << rvals(e) << " .Time is "
                 << getTime() << endl;
        }
        if (i == 10) {
            cout << "After 10 steps queueSize = " << rval(0) << " and served is " << rvals(e) << " .Time is "
                 << getTime() << endl;
        }
        if (i == 15) {
            cout << "After 15 steps queueSize = " << rval(0) << " and served is " << rvals(e) << " .Time is "
                 << getTime() << endl;
        }
    }
    cout << "final served is " << rvals(e) << " .Time is " << getTime() << endl;
    setSimulatorForNewSimulation(987654321);
    cout << "Running to the end now. New instance" << endl;
    performWholeSimulation();
    cout << "final served is " << rvals(e) << " .Time is " << getTime() << endl;
    double test = rval(0);
    cout << "just checking queue size is " << test << endl;
    /*
    for(int i = 0; i<20;i++){
        simulator->performOneStepOfSimulation();
        if(i==5){
            cout << "After 5 steps queueSize = " << simulator->rval(0) << " and served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
        }
        if(i==10){
            cout << "After 10 steps queueSize = " << simulator->rval(0) << " and served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
        }
        if(i==15){
            cout << "After 15 steps queueSize = " << simulator->rval(0) << " and served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
        }
    }
    cout << "final served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
    simulator->setSimulatorForNewSimulation(123);
    cout << "Next round (should be the same)" << endl;
    for(int i = 0; i<20;i++){
        simulator->performOneStepOfSimulation();
        if(i==5){
            cout << "After 5 steps queueSize = " << simulator->rval(0) << " and served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
        }
        if(i==10){
            cout << "After 10 steps queueSize = " << simulator->rval(0) << " and served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
        }
        if(i==15){
            cout << "After 15 steps queueSize = " << simulator->rval(0) << " and served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
        }
    }
    cout << "final served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
    simulator->setSimulatorForNewSimulation(345678);
    cout << "Trying new seed" << endl;
    for(int i = 0; i<20;i++){
        simulator->performOneStepOfSimulation();
        if(i==5){
            cout << "After 5 steps queueSize = " << simulator->rval(0) << " and served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
        }
        if(i==10){
            cout << "After 10 steps queueSize = " << simulator->rval(0) << " and served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
        }
        if(i==15){
            cout << "After 15 steps queueSize = " << simulator->rval(0) << " and served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
        }
    }
    cout << "final served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
    simulator->setSimulatorForNewSimulation(987654321);
    cout << "Running to the end now. New instance" << endl;
    simulator->performWholeSimulation();
    cout << "final served is " << simulator->rval("") << " .Time is " << simulator->getTime() << endl;
     */

}