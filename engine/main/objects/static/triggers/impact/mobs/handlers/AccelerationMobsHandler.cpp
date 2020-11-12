//
// Created by roman on 12.11.2020.
//

#include "AccelerationMobsHandler.h"

Triggers::AccelerationMobsHandler::AccelerationMobsHandler(float accelerationX, float accelerationY)
        : X_ACCELERATION(accelerationX), Y_ACCELERATION(accelerationY) {}

void Triggers::AccelerationMobsHandler::handle(Mobs::Mob &object) const noexcept {
    object.addSpeed(X_ACCELERATION, Y_ACCELERATION);
}
