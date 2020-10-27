//
// Created by roman on 30.09.2020.
//

#include "GravityEffectGenerator.h"
#include "../../../../static/effects/gravity/GravityEffect.h"

Generate::GravityEffectGenerator::GravityEffectGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::GravityEffectGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addEffect(new Effects::GravityEffect(std::stof(data.at("X_ACCELERATION")), std::stof(data.at("Y_ACCELERATION"))));
}
