//
// Created by roman on 29.10.2020.
//

#include "SingleMobsAudioTriggerGenerator.h"
#include "../../../../static/triggers/audio/mobs/SingleMobsAudioTrigger.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Creation::SingleMobsAudioTriggerGenerator::SingleMobsAudioTriggerGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::SingleMobsAudioTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::SingleMobsAudioTrigger(RD::commonArea(data), RD::loadMusic(data, m_source)));
}
