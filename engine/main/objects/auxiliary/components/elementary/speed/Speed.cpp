//
// Created by roman on 07.11.2020.
//

#include "Speed.h"

Components::Speed::Speed(const std::pair<float, float> &speed) : xSpeed(speed.first), ySpeed(speed.second) {}

Components::Speed::Speed(float xSpeed, float ySpeed) : xSpeed(xSpeed), ySpeed(ySpeed) {}

void Components::Speed::add(float offsetX, float offsetY) noexcept {
    xSpeed += offsetX;
    ySpeed += offsetY;
}

bool Components::Speed::isZero() const noexcept {
    return (xSpeed == 0) && (ySpeed == 0);
}
