//
// Created by roman on 10.11.2020.
//

#include "PlayerDeathZoneGenerator.h"
#include "../../../../static/triggers/impact/player/ImpactPlayerZone.h"
#include "../../../../static/triggers/impact/handlers/DeathHandler.h"
#include "../reduction/AreaReduction.h"

Creation::PlayerDeathZoneGenerator::PlayerDeathZoneGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::PlayerDeathZoneGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addTrigger(new Triggers::ImpactPlayerZone(RD::commonArea(data), new Triggers::DeathHandler<Mobs::Player>()));
}
