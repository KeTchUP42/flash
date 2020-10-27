//
// Created by roman on 15.10.2020.
//

#include "PlayerAudioTriggerGenerator.h"
#include "../../../../static/triggers/audio/player/PlayerAudioTrigger.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Generate::PlayerAudioTriggerGenerator::PlayerAudioTriggerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::PlayerAudioTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::PlayerAudioTrigger(commonArea(data), loadMusic(data, m_source)));
}
