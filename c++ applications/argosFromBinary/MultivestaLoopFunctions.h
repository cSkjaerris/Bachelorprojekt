//
// Created by Casper Skjærris on 2019-04-29.
//

#ifndef ARGOSFROMBINARY_MULTIVESTALOOPFUNCTIONS_H
#define ARGOSFROMBINARY_MULTIVESTALOOPFUNCTIONS_H

#include <argos3/core/simulator/loop_functions.h>
#include <argos3/core/simulator/entity/floor_entity.h>

using namespace argos;

class MultivestaLoopFunctions : public CLoopFunctions {

public:
    MultivestaLoopFunctions();
    virtual ~MultivestaLoopFunctions() {}

    virtual void Init(TConfigurationNode& t_tree);
    virtual double GetXCoordinate();

private:
    CFloorEntity* m_pcFloor;
    CRandom::CRNG* m_pcRNG;

};


#endif //ARGOSFROMBINARY_MULTIVESTALOOPFUNCTIONS_H
