//
// Created by Casper Skjærris on 2019-03-14.
//

#include "JNALink.h"
#include "iostream"
#include "BankSimulator.h"

using namespace std;

int main() {
    string sp = "/Users/casperskjaerris/Documents/cApp/settings.ini";
    char* settingsPath = new char[sp.length()+1];
    strcpy(settingsPath,sp.c_str());

    string qs = "queueSize";
    char* queueSize = new char[qs.length()+1];
    strcpy(queueSize,qs.c_str());
    string s = "served";
    char* served = new char[s.length()+1];
    strcpy(served,s.c_str());

    string a = "hasArrived";
    char* hasArrived = new char[a.length()+1];
    strcpy(hasArrived,a.c_str());

    //auto abc = new BankSimulator(123,settingsPath);
    //registerSimulator(abc);

    cout << "size of events are " << sizeof(Event) << endl;
    cout << "size of events are " << sizeof(Arrival) << endl;

    for (int j = 0; j < 2; j++) {
        setSimulatorForNewSimulation(123, settingsPath);
        for (int i = 0; i < 20; i++) {
            performOneStepOfSimulation();
            if (i == 5) {
                cout << "After 5 steps queueSize = " << rvals(queueSize) << " and served is " << rvals(served) << " .Time is "
                     << getTime() << endl;
            }
            if (i == 10) {
                cout << "After 10 steps queueSize = " << rvals(queueSize) << " and served is " << rvals(served) << " .Time is "
                     << getTime() << endl;
            }
            if (i == 15) {
                cout << "After 15 steps queueSize = " << rvals(queueSize) << " and served is " << rvals(served) << " .Time is "
                     << getTime() << endl;
            }
        }
        cout << "final served is " << rvals(served) << " .Time is " << getTime() << endl;
        cout << "Trying again with same seed" << endl;
    }
    setSimulatorForNewSimulation(345678, settingsPath);
    cout << "Trying new seed" << endl;
    for (int i = 0; i < 20; i++) {
        performOneStepOfSimulation();
        if (i == 5) {
            cout << "After 5 steps queueSize = " << rvals(queueSize) << " and served is " << rvals(served) << " .Time is "
                 << getTime() << "arrivals is" << rvals(hasArrived) << endl;
        }
        if (i == 10) {
            cout << "After 10 steps queueSize = " << rvals(queueSize) << " and served is " << rvals(served) << " .Time is "
                 << getTime() << endl;
        }
        if (i == 15) {
            cout << "After 15 steps queueSize = " << rvals(queueSize) << " and served is " << rvals(served) << " .Time is "
                 << getTime() << endl;
        }
    }
    cout << "final served is " << rvals(served) << " .Time is " << getTime() << endl;
    setSimulatorForNewSimulation(987654321, settingsPath);
    cout << "Running to the end now. New instance" << endl;
    performWholeSimulation();
    cout << "final served is " << rvals(served) <<  "final arrived is" << rvals(hasArrived) <<" .Time is " << getTime() << endl;
    double test = rvals(queueSize);
    cout << "just checking queue size is " << test << endl;

}