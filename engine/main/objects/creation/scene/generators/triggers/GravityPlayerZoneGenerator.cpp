//
// Created by roman on 12.11.2020.
//

#include "GravityPlayerZoneGenerator.h"
#include "../../../../static/triggers/impact/player/ImpactPlayerZone.h"
#include "../../../../static/triggers/impact/handlers/GravityHandler.h"
#include "../reduction/AreaReduction.h"

Creation::GravityPlayerZoneGenerator::GravityPlayerZoneGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::GravityPlayerZoneGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    Triggers::Handler<Mobs::Player> *handler = new Triggers::GravityHandler<Mobs::Player>(
            std::stof(data.at("X_ACCELERATION")), std::stof(data.at("Y_ACCELERATION")));
    unifier.addTrigger(new Triggers::ImpactPlayerZone(RD::commonArea(data), handler));
}
