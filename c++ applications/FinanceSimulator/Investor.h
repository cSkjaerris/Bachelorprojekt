//
// Created by Casper Skjærris on 2019-03-06.
//

#ifndef FINANCESIMULATOR_INVESTOR_H
#define FINANCESIMULATOR_INVESTOR_H

#include <map>
#include <random>

using namespace std;

enum ReoptimizationFrequency{
    Daily, Monthly, Quarterly, Annually
};

struct InvestorTemplateXSecurity{
    int totalBoughtToday;
    int numberOfBuyers;
    int idOfLargestBuyer;
    int purchaseOfLargestBuyer;
    int totalSoldToday;
    int numberOfSellers;
    int idOfLargestSeller;
    int saleOfLargestSeller;
};

struct InvestorXSecurity{
    double Xunits;
};

struct Investor {
    int id;
    int investorTemplateId;
    double startingWealth;
    double depositsReceived;
    double withdrawalsPaid;
    double withdrawalsOwed;
    double collateralForShortPositions;
    double currentWealth;
};

struct InvestorTemplate{
    int templateId;
    int statisticianId;
    int traderTemplateId;
    double meanLog10InitWealth;
    double sigmaLog10InitWealth;
    double K; //risk aversion parameter
    ReoptimizationFrequency reoptimizationFrequency;
    map<int,Investor>* investors;
    int numberOfInvestors;
    lognormal_distribution<double> distribution;
};

#endif //FINANCESIMULATOR_INVESTOR_H
