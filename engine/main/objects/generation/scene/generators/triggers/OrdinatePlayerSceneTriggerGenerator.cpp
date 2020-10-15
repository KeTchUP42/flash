//
// Created by roman on 05.10.2020.
//

#include "OrdinatePlayerSceneTriggerGenerator.h"
#include "../../../../static/triggers/scene/player/PlayerSceneTrigger.h"
#include "../../../../static/triggers/scene/player/handlers/OrdinatePositionPlayerHandler.h"
#include "../reduction/AreaReduction.h"

Generate::OrdinatePlayerSceneTriggerGenerator::
OrdinatePlayerSceneTriggerGenerator(Generate::Pools::SourcePool &pool, Screen::StateChangeable *context)
        : SceneTriggerGenerator(pool, context) {}

void Generate::OrdinatePlayerSceneTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //target Y
    float targetY = (data.at("TARGET_Y") == "MAX") ? target.getSize().y : std::stof(data.at("TARGET_Y")); // Checking value.

    unifier.addTrigger(new Triggers::PlayerSceneTrigger(
            data.at("NEXT_SCENE"), commonArea(data),
            new Triggers::OrdinatePositionPlayerHandler(targetY), m_context));
}
