//
// Created by roman on 01.11.2020.
//

#include "RotatingMath.h"

#include <math.h>

Components::Point
Components::Math::pointToPointRotation(const Components::Point &base, float angle, const Components::Point &target) noexcept {
    double angleInRadians = angle * M_PI / 180;
    double sinAngle = std::sin(angleInRadians);
    double cosAngle = std::cos(angleInRadians);

    return Components::Point(target.x + (target.y - base.y) * sinAngle + (base.x - target.x) * cosAngle,
                             target.y + (base.y - target.y) * cosAngle + (base.x - target.x) * sinAngle);
}

std::pair<float, float>
Components::Math::pointToPointRotationOffset(const Components::Point &base, float angle, const Components::Point &target) noexcept {
    double angleInRadians = angle * M_PI / 180;
    double sinAngle = std::sin(angleInRadians);
    double cosAngle = std::cos(angleInRadians);

    return std::pair<float, float>((target.y - base.y) * sinAngle + (base.x - target.x) * cosAngle,
                                   (base.y - target.y) * cosAngle + (base.x - target.x) * sinAngle);
}
