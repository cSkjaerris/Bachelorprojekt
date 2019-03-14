#ifndef FINANCESIMULATOR_LIBRARY_H
#define FINANCESIMULATOR_LIBRARY_H

#include <vector>
#include <map>
#include <math.h>
#include <random>

#include "Security.h"
#include "Statistician.h"
#include "Investor.h"
#include "Trader.h"

using namespace std;
enum Event{
    Reoptimize,
    ReviewOrder,
    EndDay
};
class FinanceSimulator{
private:
    double simTime;
    double endTime;
    double RFLendRatePerDay;
    double BrokerRatePerDAy;
    int liquidationTraderNumber;
    unsigned int seed;
    vector<Security>* securities;
    vector<int>* keptTradingDays;
    vector<int>* keptMonths;
    map<int,Statistician>* statisticians;
    map<int,InvestorTemplate>* investorTemplates;
    map<int,PortfolioAnalyst>* portfolioAnalysts;
    map<int,TraderTemplate>* traderTemplates;
    map<int,Trader>* traders;
    map<double,Event>* eventMapping;
    default_random_engine generator;
    void initialization();
    void reoptimize(Investor* investor);
    void reviewOrder();
    void endOfDay();
    double logNormalDistribution(double mean, double stdDeviation);
};
#endif