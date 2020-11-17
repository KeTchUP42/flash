//
// Created by roman on 15.11.2020.
//

#include "GravityZoneGenerator.h"
#include "../../../../static/triggers/impact/mobs/ImpactMobsZone.h"
#include "../../../../static/triggers/impact/player/ImpactPlayerZone.h"
#include "../../../../static/triggers/impact/handlers/GravityHandler.h"
#include "../reduction/AreaReduction.h"

Creation::GravityZoneGenerator::GravityZoneGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::GravityZoneGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    Components::Area area = commonArea(data);
    float xAcceleration = std::stof(data.at("X_ACCELERATION"));
    float yAcceleration = std::stof(data.at("Y_ACCELERATION"));

    Triggers::Handler<Mobs::Mob> *mobHandler = new Triggers::GravityHandler<Mobs::Mob>(xAcceleration, yAcceleration);
    unifier.addTrigger(new Triggers::ImpactMobsZone(area, mobHandler));

    Triggers::Handler<Mobs::Player> *playerHandler = new Triggers::GravityHandler<Mobs::Player>(xAcceleration, yAcceleration);
    unifier.addTrigger(new Triggers::ImpactPlayerZone(area, playerHandler));
}
