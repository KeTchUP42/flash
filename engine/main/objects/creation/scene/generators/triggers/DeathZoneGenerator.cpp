//
// Created by roman on 15.11.2020.
//

#include "DeathZoneGenerator.h"
#include "../../../../static/triggers/impact/mobs/ImpactMobsZone.h"
#include "../../../../static/triggers/impact/player/ImpactPlayerZone.h"
#include "../../../../static/triggers/impact/handlers/DeathHandler.h"
#include "../reduction/AreaReduction.h"

Creation::DeathZoneGenerator::DeathZoneGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::DeathZoneGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    Components::Area area = RD::commonArea(data);
    unifier.addTrigger(new Triggers::ImpactMobsZone(area, new Triggers::DeathHandler<Mobs::Mob>()));
    unifier.addTrigger(new Triggers::ImpactPlayerZone(area, new Triggers::DeathHandler<Mobs::Player>()));
}
