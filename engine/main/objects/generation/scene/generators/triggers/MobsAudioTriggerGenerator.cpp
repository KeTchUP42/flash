//
// Created by roman on 19.10.2020.
//

#include "MobsAudioTriggerGenerator.h"
#include "../../../../static/triggers/audio/mobs/MobsAudioTrigger.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Generate::MobsAudioTriggerGenerator::MobsAudioTriggerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::MobsAudioTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addTrigger(new Triggers::MobsAudioTrigger(commonArea(data), loadMusic(data, m_source)));
}
