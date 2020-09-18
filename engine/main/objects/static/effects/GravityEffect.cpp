//
// Created by roman on 11.09.2020.
//

#include "GravityEffect.h"

Effects::GravityEffect::GravityEffect(float accelerationX, float accelerationY)
        : X_ACCELERATION(accelerationX), Y_ACCELERATION(accelerationY) {}

void Effects::GravityEffect::applyEffect(Unite::Unifier *unifier) {
    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {
        player->addSpeed(X_ACCELERATION, Y_ACCELERATION);
    }

    for (const std::shared_ptr<Mobs::Monster> &monster : unifier->getMonsters()) {
        monster->addSpeed(X_ACCELERATION, Y_ACCELERATION);
    }
}