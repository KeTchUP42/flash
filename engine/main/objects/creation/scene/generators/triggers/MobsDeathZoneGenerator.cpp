//
// Created by roman on 11.11.2020.
//

#include "MobsDeathZoneGenerator.h"
#include "../../../../static/triggers/impact/mobs/ImpactMobsZone.h"
#include "../../../../static/triggers/impact/handlers/DeathHandler.h"
#include "../reduction/AreaReduction.h"

Creation::MobsDeathZoneGenerator::MobsDeathZoneGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::MobsDeathZoneGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::ImpactMobsZone(commonArea(data), new Triggers::DeathHandler<Mobs::Mob>()));
}
