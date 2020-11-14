//
// Created by roman on 10.11.2020.
//

#include "PlayerDeathTriggerGenerator.h"
#include "../../../../static/triggers/impact/player/ImpactPlayerTrigger.h"
#include "../../../../static/triggers/impact/handlers/DeathHandler.h"
#include "../reduction/AreaReduction.h"

Generate::PlayerDeathTriggerGenerator::PlayerDeathTriggerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::PlayerDeathTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::ImpactPlayerTrigger(commonArea(data), new Triggers::DeathHandler<Mobs::Player>()));
}
