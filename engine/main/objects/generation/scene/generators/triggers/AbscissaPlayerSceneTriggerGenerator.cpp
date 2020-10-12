//
// Created by roman on 05.10.2020.
//

#include "AbscissaPlayerSceneTriggerGenerator.h"
#include "../../../../static/triggers/scene/player/PlayerSceneTrigger.h"
#include "../../../../static/triggers/scene/player/handlers/AbscissaPositionPlayerHandler.h"
#include "../reduction/area.h"

Generate::AbscissaPlayerSceneTriggerGenerator::
AbscissaPlayerSceneTriggerGenerator(Generate::Pools::SourcePool &pool, Screen::StateChangeable *context)
        : SceneTriggerGenerator(pool, context) {}

void Generate::AbscissaPlayerSceneTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //target X
    float targetX = (data.at("TARGET_X") == "MAX") ? target.getSize().x : std::stof(data.at("TARGET_X")); // Checking value.

    unifier.addTrigger(new Triggers::PlayerSceneTrigger(
            data.at("NEXT_SCENE"), physicalArea(data),
            new Triggers::AbscissaPositionPlayerHandler(targetX), m_context));
}
