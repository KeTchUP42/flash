//
// Created by roman on 12.11.2020.
//

#include "AccelerationMobsTriggerGenerator.h"
#include "../../../../static/triggers/impact/mobs/ImpactMobsTrigger.h"
#include "../../../../static/triggers/impact/mobs/handlers/AccelerationMobsHandler.h"
#include "../reduction/AreaReduction.h"

Generate::AccelerationMobsTriggerGenerator::AccelerationMobsTriggerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::AccelerationMobsTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    Triggers::Handler<Mobs::Mob> *handler = new Triggers::AccelerationMobsHandler(
            std::stof(data.at("X_ACCELERATION")), std::stof(data.at("Y_ACCELERATION")));
    unifier.addTrigger(new Triggers::ImpactMobsTrigger(commonArea(data), handler));
}
