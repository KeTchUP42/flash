//
// Created by roman on 05.10.2020.
//

#include "OrdinatePlayerSceneTriggerGenerator.h"
#include "../../../../static/triggers/scene/player/PlayerSceneTrigger.h"
#include "../../../../static/triggers/scene/player/handlers/OrdinatePositionPlayerHandler.h"
#include "../reduction/AreaReduction.h"

Creation::OrdinatePlayerSceneTriggerGenerator::
OrdinatePlayerSceneTriggerGenerator(Creation::Pools::SourcePool &pool, View::StateChangeable *context)
        : SceneTriggerGenerator(pool, context) {}

void Creation::OrdinatePlayerSceneTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::PlayerSceneTrigger(
            data.at("NEXT_SCENE"), commonArea(data),
            new Triggers::OrdinatePositionPlayerHandler(std::stof(data.at("TARGET_Y"))), m_context));
}
