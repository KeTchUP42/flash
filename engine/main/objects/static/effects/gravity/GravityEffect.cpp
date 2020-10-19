//
// Created by roman on 11.09.2020.
//

#include "GravityEffect.h"

Effects::GravityEffect::GravityEffect(float accelerationX, float accelerationY)
        : X_ACCELERATION(accelerationX), Y_ACCELERATION(accelerationY) {}

void Effects::GravityEffect::applyEffect(Unite::Unifier *unifier) {

    for (const std::shared_ptr<Mobs::Mob> &mob : unifier->getMobs()) {
        mob->addSpeed(X_ACCELERATION, Y_ACCELERATION);
    }

    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {
        player->addSpeed(X_ACCELERATION, Y_ACCELERATION);
    }

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle : unifier->getObstacles()) {
        if (!obstacle->getProperties().isFixed) {
            obstacle->addSpeed(X_ACCELERATION, Y_ACCELERATION);
        }
    }
}