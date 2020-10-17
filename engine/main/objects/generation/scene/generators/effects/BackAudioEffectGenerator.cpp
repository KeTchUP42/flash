//
// Created by roman on 17.10.2020.
//

#include "BackAudioEffectGenerator.h"
#include "../../../../static/effects/audio/back/BackAudioEffect.h"
#include "../reduction/CustomReduction.h"

Generate::BackAudioEffectGenerator::BackAudioEffectGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::BackAudioEffectGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addEffect(new Effects::BackAudioEffect(loadMusic(data, m_source)));
}
