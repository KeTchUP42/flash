//
// Created by roman on 19.10.2020.
//

#include "MobsAudioTriggerGenerator.h"
#include "../../../../static/triggers/audio/mobs/MobsAudioTrigger.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Creation::MobsAudioTriggerGenerator::MobsAudioTriggerGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::MobsAudioTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::MobsAudioTrigger(commonArea(data), loadMusic(data, m_source)));
}
