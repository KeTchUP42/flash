//
// Created by roman on 11.11.2020.
//

#include "MobsDeathTriggerGenerator.h"
#include "../../../../static/triggers/impact/mobs/ImpactMobsTrigger.h"
#include "../../../../static/triggers/impact/handlers/DeathHandler.h"
#include "../reduction/AreaReduction.h"

Generate::MobsDeathTriggerGenerator::MobsDeathTriggerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::MobsDeathTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::ImpactMobsTrigger(commonArea(data), new Triggers::DeathHandler<Mobs::Mob>()));
}
