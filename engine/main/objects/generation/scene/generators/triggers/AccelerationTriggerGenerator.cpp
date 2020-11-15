//
// Created by roman on 15.11.2020.
//

#include "AccelerationTriggerGenerator.h"
#include "../../../../static/triggers/impact/mobs/ImpactMobsTrigger.h"
#include "../../../../static/triggers/impact/player/ImpactPlayerTrigger.h"
#include "../../../../static/triggers/impact/handlers/AccelerationHandler.h"
#include "../reduction/AreaReduction.h"

Generate::AccelerationTriggerGenerator::AccelerationTriggerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::AccelerationTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    Components::Area area = commonArea(data);
    float xAcceleration = std::stof(data.at("X_ACCELERATION"));
    float yAcceleration = std::stof(data.at("Y_ACCELERATION"));

    Triggers::Handler<Mobs::Mob> *mobHandler = new Triggers::AccelerationHandler<Mobs::Mob>(xAcceleration, yAcceleration);
    unifier.addTrigger(new Triggers::ImpactMobsTrigger(area, mobHandler));

    Triggers::Handler<Mobs::Player> *playerHandler = new Triggers::AccelerationHandler<Mobs::Player>(xAcceleration, yAcceleration);
    unifier.addTrigger(new Triggers::ImpactPlayerTrigger(area, playerHandler));
}
