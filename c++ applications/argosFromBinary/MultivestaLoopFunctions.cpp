//
// Created by Casper Skjærris on 2019-04-29.
//

#include <argos3/plugins/robots/foot-bot/simulator/footbot_entity.h>
#include "MultivestaLoopFunctions.h"

MultivestaLoopFunctions::MultivestaLoopFunctions() : m_pcFloor(NULL), m_pcRNG(NULL){

}

void MultivestaLoopFunctions::Init(TConfigurationNode &t_tree) {
    try {
        m_pcFloor = &GetSpace().GetFloorEntity();
        m_pcRNG = CRandom::CreateRNG("argos");
    }
    catch(CARGoSException& ex) {
        THROW_ARGOSEXCEPTION_NESTED("Error parsing loop functions!", ex);
    }
}

void MultivestaLoopFunctions::Reset() {
    //Reset counters here once implemented
}



double MultivestaLoopFunctions::GetXCoordinate() {
    // Get handle to foot-bot entity
    CFootBotEntity& cFootBot = dynamic_cast<CFootBotEntity&>(GetSpace().GetEntity("fb0"));
    return cFootBot.GetEmbodiedEntity().GetOriginAnchor().Position.GetX();
}


REGISTER_LOOP_FUNCTIONS(MultivestaLoopFunctions, "multivesta_loop_functions")