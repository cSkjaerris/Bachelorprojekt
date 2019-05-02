#ifndef INVENTORYMANAGEMENTSIMULATOR_LIBRARY_H
#define INVENTORYMANAGEMENTSIMULATOR_LIBRARY_H

#include <random>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

#include "Shop.h"
#include "SimulatorLink.h"

using namespace std;
enum Event{
    DailyDemand,
    CustomerOrder,
    ProductHandover,
    CustomerPayment,
    ReplenishmentOrder,
    Delivery,
    PaymentForDelivery
};

class InventoryManagementSimulator : public SimulatorLink{
private:
    int simulationTime;
    int endSimulation;
    unsigned int seed;
    default_random_engine generator;
    uniform_int_distribution<int> daysForResplenishingDistribution;
    uniform_int_distribution<int> sampleQuantityDistribution;
    Shop* singleProductShop;
    map<int,vector<Event>>* eventMapping;
    map<int,int>* deliveryMap;
    int numberOfRestocking;
    int soldProducts;
    int lostSales;
    void sendDeliveryRequest(int orderSize);
    void dailyDemand();
    void delivery();
    void reset(unsigned int seed, string settingsPath);
public:
    InventoryManagementSimulator(unsigned int seed, string settingsPath);
    ~InventoryManagementSimulator() = default;
    void performSimulationStep();
    void completeSimulation();
    int getNumberOfRestocking() const;

    int getSoldProducts() const;

    int getLostSales() const;
    int getCurrentStock() const;
    double getTime() override;
    void performOneStepOfSimulation() override;
    void performWholeSimulation() override;
    void setSimulatorForNewSimulation(unsigned int seed, string settingsPath)  override;
    double rval(int obs)  override;
    double rval(string obs)  override;

};

#endif