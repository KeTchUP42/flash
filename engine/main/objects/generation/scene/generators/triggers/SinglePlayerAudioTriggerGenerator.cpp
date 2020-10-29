//
// Created by roman on 29.10.2020.
//

#include "SinglePlayerAudioTriggerGenerator.h"
#include "../../../../static/triggers/audio/player/SinglePlayerAudioTrigger.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Generate::SinglePlayerAudioTriggerGenerator::SinglePlayerAudioTriggerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::SinglePlayerAudioTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::SinglePlayerAudioTrigger(commonArea(data), loadMusic(data, m_source)));
}
