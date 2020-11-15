//
// Created by roman on 15.11.2020.
//

#include "DeathTriggerGenerator.h"
#include "../../../../static/triggers/impact/mobs/ImpactMobsTrigger.h"
#include "../../../../static/triggers/impact/player/ImpactPlayerTrigger.h"
#include "../../../../static/triggers/impact/handlers/DeathHandler.h"
#include "../reduction/AreaReduction.h"

Generate::DeathTriggerGenerator::DeathTriggerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::DeathTriggerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    Components::Area area = commonArea(data);
    unifier.addTrigger(new Triggers::ImpactMobsTrigger(area, new Triggers::DeathHandler<Mobs::Mob>()));
    unifier.addTrigger(new Triggers::ImpactPlayerTrigger(area, new Triggers::DeathHandler<Mobs::Player>()));
}
