//
// Created by roman on 12.11.2020.
//

#include "AccelerationPlayerHandler.h"

Triggers::AccelerationPlayerHandler::AccelerationPlayerHandler(float accelerationX, float accelerationY)
        : X_ACCELERATION(accelerationX), Y_ACCELERATION(accelerationY) {}

void Triggers::AccelerationPlayerHandler::handle(Mobs::Player &object) const noexcept {
    object.addSpeed(X_ACCELERATION, Y_ACCELERATION);
}
