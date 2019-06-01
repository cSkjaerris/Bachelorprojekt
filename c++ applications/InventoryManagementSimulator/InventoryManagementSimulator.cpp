#include "InventoryManagementSimulator.h"

InventoryManagementSimulator::InventoryManagementSimulator(unsigned int seed, string settingsPath){

    deliveryMap = new map<int,int>();
    eventMapping = new map<int,vector<Event>>();
    singleProductShop = new Shop();
    singleProductShop->inventory = new Inventory();
    this->seed = seed;

    reset(seed,settingsPath);
}

void InventoryManagementSimulator::dailyDemand() {
    /*int demand; // For the comparison version
    if (simulationTime == 1){
        demand = 25;
    } else {
        demand = sampleQuantityDistribution(generator); //Get random demand for the day
    }*/

    int demand = sampleQuantityDistribution(generator); //Get random demand for the day

    //If product in stock is greater than demand of the day, sell the products
    if (singleProductShop->inventory->productInStock >= demand){
        //If product in stock will be lower than the reorder point, place an order to get target inventory
        if(singleProductShop->inventory->productInStock - demand < singleProductShop->inventory->reorderPoint &&
            singleProductShop->inventory->productInStock > singleProductShop->inventory->reorderPoint){
            int newInventory = singleProductShop->inventory->productInStock - demand;
            int differenceBetweenTargetAndNew = singleProductShop->inventory->targetInventory - newInventory;
            sendDeliveryRequest(differenceBetweenTargetAndNew);
        }
        singleProductShop->inventory->productInStock -= demand;
        soldProducts +=demand;
    } else {
        // If not enough product for the demand, lost sales is increased by the difference of stock and demand
        // and stock is set to 0
        lostSales += demand - singleProductShop->inventory->productInStock;
        singleProductShop->inventory->productInStock = 0;
        //If no deliveries has been scheduled, place an order on the target inventory
        if(deliveryMap->empty()){
            sendDeliveryRequest(singleProductShop->inventory->targetInventory);
        }
    }
    //Place a daily demand schedule for tomorrow, if it's not the last day of the simulation
    if(simulationTime < endSimulation) {
        auto vectorOnTomorrowEntry = eventMapping->find(simulationTime + 1);
        vector<Event> *vectorOnTomorrow;
        if (vectorOnTomorrowEntry != eventMapping->end()) {
            vectorOnTomorrow = &vectorOnTomorrowEntry->second;
        } else {
            vectorOnTomorrow = new vector<Event>();
        }
        vectorOnTomorrow->push_back(DailyDemand);
        eventMapping->insert(pair(simulationTime + 1, *vectorOnTomorrow));
    }
}

void InventoryManagementSimulator::delivery() {
    int delivery = deliveryMap->at(simulationTime);
    singleProductShop->inventory->productInStock += delivery;
    deliveryMap->erase(simulationTime);
    numberOfRestocking++;
}

void InventoryManagementSimulator::performSimulationStep() {
    if(simulationTime <= endSimulation && !eventMapping->empty()){
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
    while(simulationTime <= endSimulation && !eventMapping->empty())
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

int InventoryManagementSimulator::getCurrentStock() const {
    return singleProductShop->inventory->productInStock;
}

void InventoryManagementSimulator::sendDeliveryRequest(int orderSize) {
    auto shipmentDay = daysForResplenishingDistribution(generator) + simulationTime;
    /*int randomNumb = daysForResplenishingDistribution(generator); // use this snippet if delivery is not uniform
    int shipmentDay = simulationTime;
    if(randomNumb < 25)
        shipmentDay += 1;
    else if (randomNumb < 85)
        shipmentDay += 2;
    else
        shipmentDay +=3;*/

    if (shipmentDay <= endSimulation) {
        auto vectorOnShipmentDayEntry = eventMapping->find(shipmentDay);
        vector<Event> *vectorOnShipmentDay;
        if (vectorOnShipmentDayEntry != eventMapping->end()) {
            vectorOnShipmentDay = &vectorOnShipmentDayEntry->second;
        } else {
            vectorOnShipmentDay = new vector<Event>();
        }
        vectorOnShipmentDay->insert(vectorOnShipmentDay->begin(), Delivery);
        eventMapping->insert(pair(shipmentDay, *vectorOnShipmentDay));
        int currentDeliveryQuantity = 0;
        auto currentDeliveryQuantityEntry = deliveryMap->find(shipmentDay);
        if (currentDeliveryQuantityEntry != deliveryMap->end()) {
            currentDeliveryQuantity = currentDeliveryQuantityEntry->second;
        }
        orderSize += currentDeliveryQuantity;
        deliveryMap->insert(pair(shipmentDay, orderSize));
    }
}

double InventoryManagementSimulator::getTime(){
    return simulationTime;
}
void InventoryManagementSimulator::performOneStepOfSimulation(){
    performSimulationStep();
}
void InventoryManagementSimulator::performWholeSimulation() {
    completeSimulation();
}
void InventoryManagementSimulator::setSimulatorForNewSimulation(unsigned int seed, string settingsPath) {
    this->seed = seed;
    reset(seed, settingsPath);

}
double InventoryManagementSimulator::rval(int obs){
    return 0;
}
double InventoryManagementSimulator::rval(string obs){
    if (obs == "numberOfRestocking"){
        return numberOfRestocking;
    }
    if (obs == "soldProducts"){
        return soldProducts;
    }
    if (obs == "lostSales"){
        return lostSales;
    }
    if (obs == "stock"){
        return singleProductShop->inventory->productInStock;
    }
    return -1;
}

void InventoryManagementSimulator::reset(unsigned int seed, string settingsPath ){
    fstream settingsFile;
    settingsFile.open(settingsPath);
    if(!settingsFile){
        cerr << "Could not load settings file";
        exit(1);
    }

    int endTime, targetInv, reorderPoint, orderMinTime, orderMaxTime, dailyDemandMin, dailyDemandMax;
    settingsFile >> endTime;
    settingsFile >> targetInv;
    settingsFile >> reorderPoint;
    settingsFile >> orderMinTime;
    settingsFile >> orderMaxTime;
    settingsFile >> dailyDemandMin;
    settingsFile >> dailyDemandMax;
    settingsFile.close();

    daysForResplenishingDistribution = uniform_int_distribution(orderMinTime,orderMaxTime);
    //daysForResplenishingDistribution = uniform_int_distribution(1,99);
    sampleQuantityDistribution = uniform_int_distribution(dailyDemandMin,dailyDemandMax);
    generator =  default_random_engine(seed);
    simulationTime = 0;
    endSimulation = endTime;
    deliveryMap->clear();

    numberOfRestocking = 0;
    soldProducts = 0;
    lostSales = 0;
    singleProductShop->inventory->targetInventory = targetInv;
    singleProductShop->inventory->reorderPoint = reorderPoint;


    auto initialStock = uniform_int_distribution(singleProductShop->inventory->reorderPoint,singleProductShop->inventory->targetInventory);
    singleProductShop->inventory->productInStock = initialStock(generator);
    //singleProductShop->inventory->productInStock = 80;
    eventMapping->clear();

    auto firstDailyDemand = new vector<Event>();
    firstDailyDemand->insert(firstDailyDemand->begin(),DailyDemand);
    eventMapping->insert(pair(1,*firstDailyDemand));
}
