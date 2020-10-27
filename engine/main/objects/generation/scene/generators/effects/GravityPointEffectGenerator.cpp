//
// Created by roman on 08.10.2020.
//

#include "GravityPointEffectGenerator.h"
#include "../../../../static/effects/gravity/GravityPointEffect.h"
#include "../reduction/ElementaryReduction.h"

Generate::GravityPointEffectGenerator::GravityPointEffectGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::GravityPointEffectGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addEffect(new Effects::GravityPointEffect(position(data, "POSITION"), std::stof(data.at("ACCELERATION"))));
}
