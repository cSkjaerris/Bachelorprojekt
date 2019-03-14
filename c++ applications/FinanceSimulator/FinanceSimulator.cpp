#include "FinanceSimulator.h"

#include <iostream>

void FinanceSimulator::initialization() {
    endTime = 730;
    simTime = 0;
    seed = 9876543;
    srand(seed);
    generator = default_random_engine(seed);

    investorTemplates = new map<int,InvestorTemplate>();
    traderTemplates = new map<int,TraderTemplate>();
    traders = new map<int,Trader>();
    statisticians = new map<int,Statistician>();
    portfolioAnalysts = new map<int,PortfolioAnalyst>();

    auto liquidationDist = uniform_real_distribution(-1,0);
    //create liquidation trader
    auto *liquidationTemplate = new TraderTemplate();
    liquidationTemplate->buyAlpha = liquidationDist(generator);
    liquidationTemplate->buyBeta = liquidationDist(generator);
    liquidationTemplate->sellAlpha = liquidationDist(generator);
    liquidationTemplate->sellBeta = liquidationDist(generator);
    liquidationTemplate->buyAlphaInc = liquidationTemplate->buyAlpha*1.2;
    liquidationTemplate->buyBetaInc = liquidationTemplate->buyBeta*1.2;
    liquidationTemplate->sellAlphaInc = liquidationTemplate->sellAlpha*1.2;
    liquidationTemplate->sellBetaInc = liquidationTemplate->sellBeta*1.2;
    liquidationTemplate->sellMaxNumberOfPriceChanges = 5;
    liquidationTemplate->sellFirstTimeWait = 5;
    liquidationTemplate->sellFollowingTimeWait = 4;
    liquidationTemplate->sellLastTimeWait = 3;
    liquidationTemplate->buyFirstTimeWait = 10;
    liquidationTemplate->buyFollowingTimeWait = 9;
    liquidationTemplate->buyLastTimeWait = 8;
    liquidationTemplate->buyMaxNumberOfPriceChanges = 5;
    liquidationTraderNumber = 10;
    traderTemplates->insert(pair(liquidationTraderNumber,*liquidationTemplate));


    //create investors and stuff
    auto uniDist = uniform_real_distribution(0,1);
    for(int i = 1; i<=2;i++){
        auto *tt = new TraderTemplate();
        tt->buyAlpha = uniDist(generator);
        tt->buyBeta = uniDist(generator);
        tt->sellAlpha = uniDist(generator);
        tt->sellBeta = uniDist(generator);
        tt->buyAlphaInc = tt->buyAlpha/10;
        tt->buyBetaInc = tt->buyBeta/10;
        tt->sellAlphaInc = tt->sellAlpha/10;
        tt->sellBetaInc = tt->sellBeta/10;
        tt->buyFirstTimeWait = 10;
        tt->buyFollowingTimeWait = 7.5;
        tt->buyLastTimeWait = 5;
        tt->buyMaxNumberOfPriceChanges = 5;
        tt->sellFirstTimeWait = 9;
        tt->sellFollowingTimeWait = 8;
        tt->sellLastTimeWait = 6;
        tt->sellMaxNumberOfPriceChanges = 5;
        pair<int, TraderTemplate> p = pair(i,*tt);
        traderTemplates->insert(p);
    }

    int investorId = 0;
    for(int i = 1; i<=5;i++) {
        auto *s = new Statistician();
        s->covMethod = CovStandard;
        s->meanMethod = Standard;
        s->id = i;
        statisticians->insert(pair(s->id,*s));
        auto *p = new PortfolioAnalyst();
        p->id = i;
        p->statisticianId = i;
        p->efficientSegments = new vector<EfficientSegment>();
        portfolioAnalysts->insert(pair(p->id,*p));
        auto *it = new InvestorTemplate();
        it->statisticianId = i;
        it->templateId = i;
        it->traderTemplateId = i % 2 +1; //keep trader id to either 1 or 2;
        it->K = 0.15*i;
        it->meanLog10InitWealth = 1000;
        it->sigmaLog10InitWealth = 70;
        it->distribution = lognormal_distribution(it->meanLog10InitWealth,it->sigmaLog10InitWealth);
        it->reoptimizationFrequency = i%2==0 ? Daily : Monthly;
        it->investors = new map<int,Investor>();
        it->numberOfInvestors = 4;
        for(int j = 0; j<it->numberOfInvestors;j++){
            auto *inv = new Investor();
            inv->id = ++investorId;
            inv->collateralForShortPositions = 0;
            inv->depositsReceived = 0;
            inv->withdrawalsOwed = 0;
            inv->withdrawalsPaid = 0;
            inv->startingWealth = it->distribution(generator);
            inv->currentWealth = inv->startingWealth;
            inv->investorTemplateId = i;
            it->investors->insert(pair(inv->id,*inv));
            auto t = new Trader();
            t->id = investorId;
            t->investorId = inv->id;
            t->traderTemplateId = it->traderTemplateId;
            traders->insert(pair(t->id,*t));
        }
        investorTemplates->insert(pair(it->templateId,*it));
    }

    //Generating securities/shares
    auto sharePriceGenerator = uniform_real_distribution(90,110);
    for(int i = 0;i<1000;i++){
        auto sec = new Security();
        sec->lastTradePrice = sharePriceGenerator(generator);
        sec->price = sec->lastTradePrice * 1.05;
        sec->startOfDayPrice = sec->price;
        sec->startOfMonthPrice = sec->price;
        sec->buyOrders = new vector<OrderSlip>();
        sec->sellOrders = new vector<OrderSlip>();
    }

    int idForFirstReoptimization = 3;
    eventMapping = new map<double,Event>();
    eventMapping->insert(pair(1,Reoptimize));


}

double FinanceSimulator::logNormalDistribution(double mean, double stdDeviation) {
    double ran = rand()/double(RAND_MAX);
    return 1.0/(stdDeviation*ran*sqrt(2*M_PI))*exp(-(pow(log(ran-mean),2)/(2*pow(stdDeviation,2))));
}

void FinanceSimulator::reoptimize(Investor* investor) {

}

