//
// Created by Casper Skjærris on 2019-03-06.
//

#ifndef FINANCESIMULATOR_TRADER_H
#define FINANCESIMULATOR_TRADER_H

#include <set>

#include "OrderSlip.h"

using namespace std;

struct TraderTemplate{
    double buyAlpha;
    double buyBeta;
    double buyAlphaInc;
    double buyBetaInc;
    double buyFirstTimeWait;
    double buyFollowingTimeWait;
    double buyLastTimeWait;
    int buyMaxNumberOfPriceChanges;
    double sellAlpha;
    double sellBeta;
    double sellAlphaInc;
    double sellBetaInc;
    double sellFirstTimeWait;
    double sellFollowingTimeWait;
    double sellLastTimeWait;
    int sellMaxNumberOfPriceChanges;
};

struct TraderXSecurity{
    int buyOrSellAmount;
    int amountOnOrder;
    vector<OrderSlip>* ordersAgainstAmount;
};

struct Trader {
    int id;
    int traderTemplateId;
    int investorId;

};


#endif //FINANCESIMULATOR_TRADER_H
