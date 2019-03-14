#ifndef INVENTORYMANAGEMENTSIMULATOR_LIBRARY_H
#define INVENTORYMANAGEMENTSIMULATOR_LIBRARY_H

#include <random>
#include <vector>
#include <map>

#include "Shop.h"

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

class InventoryManagementSimulator{
private:
    int simulationTime;
    int endSimulation;
    unsigned int seed;
    default_random_engine generator;
    uniform_int_distribution<int> daysForResplenishingDistribution;
    uniform_int_distribution<int> sampleQuantityDistribution;
    Shop* singleProductShop;
    map<int,vector<Event>>* eventMapping;
    map<int,int>* deliveryQuantity;
    int numberOfRestocking;
    int soldProducts;
    int lostSales;
    void sendDeliveryRequest(int orderSize);
    void initialize();
    void dailyDemand();
    void delivery();
public:
    InventoryManagementSimulator();
    ~InventoryManagementSimulator() = default;
    void performSimulationStep();
    void completeSimulation();
    int getNumberOfRestocking() const;

    int getSoldProducts() const;

    int getLostSales() const;

};

#endif