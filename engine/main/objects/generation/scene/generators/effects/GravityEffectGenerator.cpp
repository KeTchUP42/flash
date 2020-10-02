//
// Created by roman on 30.09.2020.
//

#include "GravityEffectGenerator.h"
#include "../../../../static/effects/GravityEffect.h"

Generating::GravityEffectGenerator::GravityEffectGenerator(Generating::SourcePool &pool) : Generator(pool) {}

void Generating::GravityEffectGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addEffect(new Effects::GravityEffect(std::stof(data.at("X_ACCELERATION")), std::stof(data.at("Y_ACCELERATION"))));
}
