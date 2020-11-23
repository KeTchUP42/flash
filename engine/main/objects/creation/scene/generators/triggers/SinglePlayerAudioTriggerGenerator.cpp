//
// Created by roman on 29.10.2020.
//

#include "SinglePlayerAudioTriggerGenerator.h"
#include "../../../../static/triggers/audio/player/SinglePlayerAudioTrigger.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Creation::SinglePlayerAudioTriggerGenerator::SinglePlayerAudioTriggerGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::SinglePlayerAudioTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::SinglePlayerAudioTrigger(RD::commonArea(data), RD::loadMusic(data, m_source)));
}
