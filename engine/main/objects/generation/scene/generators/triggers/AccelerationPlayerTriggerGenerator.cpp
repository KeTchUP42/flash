//
// Created by roman on 12.11.2020.
//

#include "AccelerationPlayerTriggerGenerator.h"
#include "../../../../static/triggers/impact/player/ImpactPlayerTrigger.h"
#include "../../../../static/triggers/impact/handlers/AccelerationHandler.h"
#include "../reduction/AreaReduction.h"

Generate::AccelerationPlayerTriggerGenerator::AccelerationPlayerTriggerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::AccelerationPlayerTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    Triggers::Handler<Mobs::Player> *handler = new Triggers::AccelerationHandler<Mobs::Player>(
            std::stof(data.at("X_ACCELERATION")), std::stof(data.at("Y_ACCELERATION")));
    unifier.addTrigger(new Triggers::ImpactPlayerTrigger(commonArea(data), handler));
}
