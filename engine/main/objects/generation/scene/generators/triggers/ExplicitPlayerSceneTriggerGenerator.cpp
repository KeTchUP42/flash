//
// Created by roman on 30.09.2020.
//

#include "ExplicitPlayerSceneTriggerGenerator.h"
#include "../../../../static/triggers/scene/ExplicitPlayerSceneTrigger.h"

Generating::ExplicitPlayerSceneTriggerGenerator::
ExplicitPlayerSceneTriggerGenerator(Generating::Pools::SourcePool &pool, Screen::StateChangeable *context)
        : SceneTriggerGenerator(pool, context) {}

void Generating::ExplicitPlayerSceneTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //point
    Components::Point point(std::stof(data.at("X")), std::stof(data.at("Y")));

    //size
    Components::Size size(std::atoi(data.at("WIDTH").c_str()), std::atoi(data.at("HEIGHT").c_str()));

    //angle
    float angle = std::stof(data.at("ANGLE"));

    //target point
    Components::Point targetPoint(std::stof(data.at("TARGET_X")), std::stof(data.at("TARGET_Y")));

    unifier.addTrigger(new Triggers::ExplicitPlayerSceneTrigger(
            data.at("NEXT_SCENE"), Components::Area(point, size, angle), targetPoint, m_context));
}
