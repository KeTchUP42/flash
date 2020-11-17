//
// Created by roman on 12.11.2020.
//

#include "GravityMobsZoneGenerator.h"
#include "../../../../static/triggers/impact/mobs/ImpactMobsZone.h"
#include "../../../../static/triggers/impact/handlers/GravityHandler.h"
#include "../reduction/AreaReduction.h"

Creation::GravityMobsZoneGenerator::GravityMobsZoneGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::GravityMobsZoneGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    Triggers::Handler<Mobs::Mob> *handler = new Triggers::GravityHandler<Mobs::Mob>(
            std::stof(data.at("X_ACCELERATION")), std::stof(data.at("Y_ACCELERATION")));
    unifier.addTrigger(new Triggers::ImpactMobsZone(commonArea(data), handler));
}
