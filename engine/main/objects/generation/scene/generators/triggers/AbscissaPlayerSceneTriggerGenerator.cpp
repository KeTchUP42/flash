//
// Created by roman on 05.10.2020.
//

#include "AbscissaPlayerSceneTriggerGenerator.h"
#include "../../../../static/triggers/scene/player/PlayerSceneTrigger.h"
#include "../../../../static/triggers/scene/player/handlers/AbscissaPositionPlayerHandler.h"

Generate::AbscissaPlayerSceneTriggerGenerator::
AbscissaPlayerSceneTriggerGenerator(Generate::Pools::SourcePool &pool, Screen::StateChangeable *context)
        : SceneTriggerGenerator(pool, context) {}

void Generate::AbscissaPlayerSceneTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //point
    Components::Point point(std::stof(data.at("X")), std::stof(data.at("Y")));

    //size
    Components::Size size(std::atoi(data.at("WIDTH").c_str()), std::atoi(data.at("HEIGHT").c_str()));

    //angle
    float angle = std::stof(data.at("ANGLE"));

    //target X
    float targetX = (data.at("TARGET_X") == "MAX") ? target.getSize().x : std::stof(data.at("TARGET_X")); // Checking value name.

    unifier.addTrigger(new Triggers::PlayerSceneTrigger(
            data.at("NEXT_SCENE"), Components::Area(point, size, angle),
            new Triggers::AbscissaPositionPlayerHandler(targetX), m_context));
}
