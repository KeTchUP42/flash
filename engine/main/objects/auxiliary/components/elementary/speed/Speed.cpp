//
// Created by roman on 07.11.2020.
//

#include "Speed.h"

void Components::Speed::add(float offsetX, float offsetY) noexcept {
    xSpeed += offsetX;
    ySpeed += offsetY;
}
