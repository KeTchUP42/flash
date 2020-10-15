//
// Created by roman on 15.10.2020.
//

#include "SimplePlayerAudioTriggerGenerator.h"
#include "../../../../static/triggers/audio/player/SimplePlayerAudioTrigger.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Generate::SimplePlayerAudioTriggerGenerator::SimplePlayerAudioTriggerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::SimplePlayerAudioTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addTrigger(new Triggers::SimplePlayerAudioTrigger(commonArea(data), loadMusic(data, m_source)));
}
