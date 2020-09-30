//
// Created by roman on 30.09.2020.
//

#include "SceneAreaTriggerGenerator.h"
#include "../../../../static/triggers/scene/PlainSceneTrigger.h"

Generating::SceneAreaTriggerGenerator::SceneAreaTriggerGenerator(Generating::SourcePool &pool, Screen::StateChangeable *context)
        : SceneTriggerGenerator(pool, context) {}

void Generating::SceneAreaTriggerGenerator::
load(const IniProcessorUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //point
    Components::Point point(std::stof(data.at("X")), std::stof(data.at("Y")));

    //size
    Components::Size size(std::atoi(data.at("WIDTH").c_str()), std::atoi(data.at("HEIGHT").c_str()));

    //angle
    float angle = std::stof(data.at("ANGLE"));

    unifier.addTrigger(new Triggers::PlainSceneTrigger(data.at("NEXT_SCENE"), Components::Area(point, size, angle), m_context));
}
