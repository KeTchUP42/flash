//
// Created by roman on 30.09.2020.
//

#include "ExplicitPlayerSceneTriggerGenerator.h"
#include "../../../../static/triggers/scene/player/PlayerSceneTrigger.h"
#include "../../../../static/triggers/scene/player/handlers/ExplicitPositionPlayerHandler.h"
#include "../reduction/AreaReduction.h"

Generate::ExplicitPlayerSceneTriggerGenerator::
ExplicitPlayerSceneTriggerGenerator(Generate::Pools::SourcePool &pool, Screen::StateChangeable *context)
        : SceneTriggerGenerator(pool, context) {}

void Generate::ExplicitPlayerSceneTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //target point
    Components::Point target_point(std::stof(data.at("TARGET_X")), std::stof(data.at("TARGET_Y")));

    unifier.addTrigger(new Triggers::PlayerSceneTrigger(
            data.at("NEXT_SCENE"), physicalArea(data),
            new Triggers::ExplicitPositionPlayerHandler(target_point), m_context));
}
