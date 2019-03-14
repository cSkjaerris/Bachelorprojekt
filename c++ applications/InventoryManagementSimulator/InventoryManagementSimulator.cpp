#include "InventoryManagementSimulator.h"

InventoryManagementSimulator::InventoryManagementSimulator(){
    daysForResplenishingDistribution = uniform_int_distribution(1,3);
    sampleQuantityDistribution = uniform_int_distribution(5,10);
    initialize();
}
void InventoryManagementSimulator::initialize() {
    seed = 9876543;
    generator = default_random_engine(seed);
    simulationTime = 0;
    endSimulation = 365;
    numberOfRestocking = 0;
    soldProducts = 0;
    lostSales = 0;
    deliveryQuantity = new map<int,int>();
    singleProductShop = new Shop();
    singleProductShop->inventory = new Inventory();
    singleProductShop->inventory->targetInventory = 25;
    singleProductShop->inventory->reorderPoint = 5;
    auto initialStock = uniform_int_distribution(singleProductShop->inventory->reorderPoint,singleProductShop->inventory->targetInventory);
    singleProductShop->inventory->productInStock = initialStock(generator);
    eventMapping = new map<int,vector<Event>>();
    auto firstDailyDemand = new vector<Event>();
    firstDailyDemand->insert(firstDailyDemand->begin(),DailyDemand);
    eventMapping->insert(pair(1,*firstDailyDemand));

}

void InventoryManagementSimulator::dailyDemand() {
    auto demand = sampleQuantityDistribution(generator);
    if (singleProductShop->inventory->productInStock >= demand){
        if(singleProductShop->inventory->productInStock - demand < singleProductShop->inventory->reorderPoint &&
            singleProductShop->inventory->productInStock > singleProductShop->inventory->reorderPoint){
            int orderQuantity = singleProductShop->inventory->targetInventory - singleProductShop->inventory->productInStock - demand;
            sendDeliveryRequest(orderQuantity);
        }
        singleProductShop->inventory->productInStock -= demand;
        soldProducts +=demand;
    } else {
        lostSales += demand - singleProductShop->inventory->productInStock;
        singleProductShop->inventory->productInStock = 0;
        if(deliveryQuantity->empty()){
            sendDeliveryRequest(singleProductShop->inventory->targetInventory);
        }
    }
    auto vectorOnTomorrowEntry = eventMapping->find(simulationTime+1);
    vector<Event>* vectorOnTomorrow;
    if(vectorOnTomorrowEntry != eventMapping->end()){
        vectorOnTomorrow = &vectorOnTomorrowEntry->second;
    } else{
        vectorOnTomorrow = new vector<Event>();
    }
    vectorOnTomorrow->push_back(DailyDemand);
    eventMapping->insert(pair(simulationTime+1,*vectorOnTomorrow));
}

void InventoryManagementSimulator::delivery() {
    int delivery = deliveryQuantity->at(simulationTime);
    singleProductShop->inventory->productInStock += delivery;
    deliveryQuantity->erase(simulationTime);
    numberOfRestocking++;
}

void InventoryManagementSimulator::performSimulationStep() {
    if(simulationTime <= endSimulation){
        auto events = eventMapping->begin();
        simulationTime = events->first;
        for (auto event : events->second){
            if(event == Delivery){
                delivery();
            }
            if(event == DailyDemand){
                dailyDemand();
            }
        }
        eventMapping->erase(simulationTime);
    }
}

void InventoryManagementSimulator::completeSimulation() {
    while(simulationTime <= endSimulation)
        performSimulationStep();

}

int InventoryManagementSimulator::getNumberOfRestocking() const {
    return numberOfRestocking;
}

int InventoryManagementSimulator::getSoldProducts() const {
    return soldProducts;
}

int InventoryManagementSimulator::getLostSales() const {
    return lostSales;
}

void InventoryManagementSimulator::sendDeliveryRequest(int orderSize) {
    auto shipmentDay = daysForResplenishingDistribution(generator) + simulationTime;
    auto vectorOnShipmentDayEntry = eventMapping->find(shipmentDay);
    vector<Event>* vectorOnShipmentDay;
    if(vectorOnShipmentDayEntry != eventMapping->end()) {
        vectorOnShipmentDay = &vectorOnShipmentDayEntry->second;
    } else{
        vectorOnShipmentDay = new vector<Event>();
    }
    vectorOnShipmentDay->insert(vectorOnShipmentDay->begin(), Delivery);
    eventMapping->insert(pair(shipmentDay, *vectorOnShipmentDay));
    int currentDeliveryQuantity = 0;
    auto currentDeliveryQuantityEntry = deliveryQuantity->find(shipmentDay);
    if (currentDeliveryQuantityEntry != deliveryQuantity->end()){
        currentDeliveryQuantity = currentDeliveryQuantityEntry->second;
    }
    orderSize +=currentDeliveryQuantity;
    deliveryQuantity->insert(pair(shipmentDay,orderSize));
}
