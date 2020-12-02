//
// Created by roman on 23.11.2020.
//

#include "MobsAnalysisReduction.h"

void RD::healthAnalysis(Mobs::Mob &mob) noexcept {
    //Validation of the health points value.
    if (mob.getProperties().healthPoints > mob.getProperties().maxHealthPoints) {
        mob.setHealthPoints(mob.getProperties().maxHealthPoints);
    }
}
