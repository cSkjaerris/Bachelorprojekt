//
// Created by Casper Skjærris on 2019-03-06.
//

#ifndef FINANCESIMULATOR_STATITICIAN_H
#define FINANCESIMULATOR_STATITICIAN_H

#include <set>

#include "CornerPortfolio.h"

using namespace std;

struct EfficientSegment{
    double highE;
    double highV;
    double lowE;
    double lowV;
    CornerPortfolio highPortfolio;
    CornerPortfolio lowPortfolio;
};

struct StatisticianXSecurity{
    double annualizedMean;
};

struct StatisticianXSecurityXSecurity{
    double annualizedCov;
};

enum EstimationMethodMean{
    Standard
};

enum EstimationMethodCov{
    CovStandard
};

struct Statistician {
    int id;
    EstimationMethodMean meanMethod;
    EstimationMethodCov covMethod;
};

struct PortfolioAnalyst{
    int id;
    int statisticianId;
    vector<EfficientSegment>* efficientSegments;
};


#endif //FINANCESIMULATOR_STATITICIAN_H
