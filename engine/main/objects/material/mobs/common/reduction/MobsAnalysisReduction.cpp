//
// Created by roman on 23.11.2020.
//

#include "MobsAnalysisReduction.h"

void Mobs::RD::healthAnalysis(Mobs::Mob &mob) noexcept {
    //Checking the correctness of the health glasses value.
    if (mob.getProperties().healthPoints > mob.getProperties().maxHealthPoints) {
        mob.setHealthPoints(mob.getProperties().maxHealthPoints);
    }
}
