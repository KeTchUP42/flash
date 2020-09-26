//
// Created by roman on 26.09.2020.
//

#include "Area.h"

const Components::Point &Components::Area::getPosition() const noexcept {
    return point;
}

const Components::Size &Components::Area::getSize() const noexcept {
    return size;
}

float Components::Area::getRotation() const noexcept {
    return angle;
}
