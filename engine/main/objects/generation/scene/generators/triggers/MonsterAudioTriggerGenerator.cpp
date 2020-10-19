//
// Created by roman on 19.10.2020.
//

#include "MonsterAudioTriggerGenerator.h"
#include "../../../../static/triggers/audio/monster/MonsterAudioTrigger.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Generate::MonsterAudioTriggerGenerator::MonsterAudioTriggerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::MonsterAudioTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addTrigger(new Triggers::MonsterAudioTrigger(commonArea(data), loadMusic(data, m_source)));
}
