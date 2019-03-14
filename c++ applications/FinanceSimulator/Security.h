//
// Created by Casper Skjærris on 2019-03-06.
//

#ifndef FINANCESIMULATOR_SECURITY_H
#define FINANCESIMULATOR_SECURITY_H

#include <vector>

#include "OrderSlip.h"

using namespace std;

struct securityXDay{
    double dailyReturn;
    int dailyVolume;
    double dailyClosePrice;
};

struct securityXMonth{
    double monthlyReturn;
    int montlyVolume;
    double monthlyClosePrice;
};

struct Security {
    double lastTradePrice;
    double price;
    double startOfDayPrice;
    double startOfMonthPrice;
    vector<OrderSlip>* buyOrders;
    vector<OrderSlip>* sellOrders;

};


#endif //FINANCESIMULATOR_SECURITY_H
