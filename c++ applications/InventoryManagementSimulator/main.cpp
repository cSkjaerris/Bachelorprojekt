//
// Created by Casper Skjærris on 2019-03-07.
//
#include <iostream>
#include "InventoryManagementSimulator.h"

using namespace std;
int main(){
    auto *simulator = new InventoryManagementSimulator();
    for (int i = 0; i < 151; i++){
        if(i%25 == 0) {
            cout << "After " << i << "steps products sold = " << simulator->getSoldProducts() << ", lost sales are = " << simulator->getLostSales() << ", and restocking are = " << simulator->getNumberOfRestocking() << endl;
        }
        simulator->performSimulationStep();
    }

    cout << "Gonna test that teh seed thing works" << endl;
    auto *sim2 = new InventoryManagementSimulator();
    for (int i = 0; i < 151; i++){
        if(i%25 == 0) {
            cout << "After " << i << "steps products sold = " << sim2->getSoldProducts() << ", lost sales are = " << sim2->getLostSales() << ", and restocking are = " << sim2->getNumberOfRestocking() << endl;
        }
        sim2->performSimulationStep();
    }

}