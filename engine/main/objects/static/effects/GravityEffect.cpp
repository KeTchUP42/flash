//
// Created by roman on 11.09.2020.
//

#include "GravityEffect.h"

Effects::GravityEffect::GravityEffect(float acceleration) : _acceleration(acceleration) {}

void Effects::GravityEffect::applyEffect(Unite::Unifier *unifier) {
    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {
        player->addSpeed(0, _acceleration);
    }
    //todo: Add other mobs.
}