//
// Created by roman on 01.11.2020.
//

#include "RotatingMath.h"

#define _USE_MATH_DEFINES

#include <math.h>

Components::Point
Components::Math::pointToPointRotation(const Components::Point &base, float angle, const Components::Point &target) noexcept {
    float angleInRadians = angle * M_PI / 180;
    float sinAngle = std::sin(angleInRadians);
    float cosAngle = std::cos(angleInRadians);

    return Components::Point(target.x + (target.y - base.y) * sinAngle + (base.x - target.x) * cosAngle,
                             target.y + (base.y - target.y) * cosAngle + (base.x - target.x) * sinAngle);
}

std::pair<float, float>
Components::Math::pointToPointRotationOffset(const Components::Point &base, float angle, const Components::Point &target) noexcept {
    float angleInRadians = angle * M_PI / 180;
    float sinAngle = std::sin(angleInRadians);
    float cosAngle = std::cos(angleInRadians);

    return std::pair<int, int>((target.y - base.y) * sinAngle + (base.x - target.x) * cosAngle,
                               (base.y - target.y) * cosAngle + (base.x - target.x) * sinAngle);
}
