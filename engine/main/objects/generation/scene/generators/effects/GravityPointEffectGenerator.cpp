//
// Created by roman on 08.10.2020.
//

#include "GravityPointEffectGenerator.h"
#include "../../../../static/effects/gravity/GravityPointEffect.h"

Generate::GravityPointEffectGenerator::GravityPointEffectGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::GravityPointEffectGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addEffect(new Effects::GravityPointEffect(
            Components::Point(std::stof(data.at("X")), std::stof(data.at("Y"))),
            std::stof(data.at("ACCELERATION"))));
}
