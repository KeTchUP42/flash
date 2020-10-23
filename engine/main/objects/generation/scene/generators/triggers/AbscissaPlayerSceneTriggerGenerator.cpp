//
// Created by roman on 05.10.2020.
//

#include "AbscissaPlayerSceneTriggerGenerator.h"
#include "../../../../static/triggers/scene/player/PlayerSceneTrigger.h"
#include "../../../../static/triggers/scene/player/handlers/AbscissaPositionPlayerHandler.h"
#include "../reduction/AreaReduction.h"

Generate::AbscissaPlayerSceneTriggerGenerator::
AbscissaPlayerSceneTriggerGenerator(Generate::Pools::SourcePool &pool, Screen::StateChangeable *context)
        : SceneTriggerGenerator(pool, context) {}

void Generate::AbscissaPlayerSceneTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addTrigger(new Triggers::PlayerSceneTrigger(
            data.at("NEXT_SCENE"), commonArea(data),
            new Triggers::AbscissaPositionPlayerHandler(std::stof(data.at("TARGET_X"))), m_context));
}
