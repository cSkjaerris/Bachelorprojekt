//
// Created by Casper Skjærris on 2019-03-07.
//
#include <iostream>
#include "InventoryManagementSimulator.h"
#include "JNALink.h"

using namespace std;
int main(){

    string sph = "/Users/casperskjaerris/Documents/cApp/InvManSetting.cfg";
    char* settingsPath = new char[sph.length()+1];
    strcpy(settingsPath,sph.c_str());

    string sp = "soldProducts";
    char* soldProducts = new char[sp.length()+1];
    strcpy(soldProducts,sp.c_str());
    string nr = "numberOfRestocking";
    char* restockings = new char[nr.length()+1];
    strcpy(restockings,nr.c_str());

    string ls = "lostSales";
    char* lostSales = new char[ls.length()+1];
    strcpy(lostSales,ls.c_str());
    setSimulatorForNewSimulation(9876543,settingsPath);

    for (int i = 0; i < 151; i++){
        if(i%25 == 0) {
            cout << "After " << i << "steps products sold = " <<rvals(soldProducts) << ", lost sales are = " << rvals(lostSales) << ", and restocking are = " << rvals(restockings) << endl;
        }
        performOneStepOfSimulation();
    }

    cout << "Gonna test that the seed thing works" << endl;
    setSimulatorForNewSimulation(9876543,settingsPath);
    for (int i = 0; i < 151; i++){
        if(i%25 == 0) {
            cout << "After " << i << "steps products sold = " <<rvals(soldProducts) << ", lost sales are = " << rvals(lostSales) << ", and restocking are = " << rvals(restockings) << endl;
        }
        performOneStepOfSimulation();
    }

    cout << "Testing new seed" << endl;
    setSimulatorForNewSimulation(324325,settingsPath);
    for (int i = 0; i < 151; i++){
        if(i%25 == 0) {
            cout << "After " << i << "steps products sold = " <<rvals(soldProducts) << ", lost sales are = " << rvals(lostSales) << ", and restocking are = " << rvals(restockings) << endl;
        }
        performOneStepOfSimulation();
    }

}