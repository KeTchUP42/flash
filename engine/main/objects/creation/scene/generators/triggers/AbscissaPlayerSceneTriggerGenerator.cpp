//
// Created by roman on 05.10.2020.
//

#include "AbscissaPlayerSceneTriggerGenerator.h"
#include "../../../../static/triggers/scene/player/PlayerSceneTrigger.h"
#include "../../../../static/triggers/scene/player/handlers/AbscissaPositionPlayerHandler.h"
#include "../reduction/AreaReduction.h"

Creation::AbscissaPlayerSceneTriggerGenerator::
AbscissaPlayerSceneTriggerGenerator(Creation::Pools::SourcePool &pool, View::StateChangeable *context)
        : SceneTriggerGenerator(pool, context) {}

void Creation::AbscissaPlayerSceneTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::PlayerSceneTrigger(
            data.at("NEXT_SCENE"), RD::commonArea(data),
            new Triggers::AbscissaPositionPlayerHandler(std::stof(data.at("TARGET_X"))), m_context));
}
