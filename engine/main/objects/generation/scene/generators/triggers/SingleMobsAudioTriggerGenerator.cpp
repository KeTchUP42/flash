//
// Created by roman on 29.10.2020.
//

#include "SingleMobsAudioTriggerGenerator.h"
#include "../../../../static/triggers/audio/mobs/SingleMobsAudioTrigger.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Generate::SingleMobsAudioTriggerGenerator::SingleMobsAudioTriggerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::SingleMobsAudioTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::SingleMobsAudioTrigger(commonArea(data), loadMusic(data, m_source)));
}
