//
// Created by roman on 16.09.2020.
//

#include "Calculations.h"

#define _USE_MATH_DEFINES

#include <math.h>

/**
 * @brief This is help function for collision function.
 * @return The value responsible for the position of the point relative to the vector.
 */
static inline int product(float Px, float Py, float Ax, float Ay, float Bx, float By) {
    return (Bx - Ax) * (Py - Ay) - (By - Ay) * (Px - Ax);
}

bool OtherUtils::collision(const Components::Point &point, const Possibilities::RectangleGetters &rectangle) noexcept {
    const float angle = rectangle.getRotation() * M_PI / 180;
    const float sinAngle = std::sin(angle);
    const float cosAngle = std::cos(angle);

    const unsigned int rectangleWidth = rectangle.getSize().width;
    const unsigned int rectangleHeight = rectangle.getSize().height;

    const float rectangleX = rectangle.getPosition().x;
    const float rectangleY = rectangle.getPosition().y;

    float rectangleX2 = -sinAngle + cosAngle * rectangleWidth + rectangleX;
    float rectangleY2 = cosAngle + sinAngle * rectangleWidth + rectangleY;

    float rectangleX3 = -sinAngle * rectangleHeight + cosAngle * rectangleWidth + rectangleX;
    float rectangleY3 = cosAngle * rectangleHeight + sinAngle * rectangleWidth + rectangleY;

    float rectangleX4 = -sinAngle * rectangleHeight + cosAngle + rectangleX;
    float rectangleY4 = cosAngle * rectangleHeight + sinAngle + rectangleY;

    return ((product(point.x, point.y, rectangleX, rectangleY, rectangleX2, rectangleY2) >= 0) &&
            (product(point.x, point.y, rectangleX2, rectangleY2, rectangleX3, rectangleY3) >= 0) &&
            (product(point.x, point.y, rectangleX3, rectangleY3, rectangleX4, rectangleY4) >= 0) &&
            (product(point.x, point.y, rectangleX4, rectangleY4, rectangleX, rectangleY) >= 0));
}

Components::Point
OtherUtils::pointToPointRotation(const Components::Point &base, float angle, const Components::Point &target) noexcept {
    const float angleInRadians = angle * M_PI / 180;
    const float sinAngle = std::sin(angleInRadians);
    const float cosAngle = std::cos(angleInRadians);

    return Components::Point(target.x + (target.y - base.y) * sinAngle + (base.x - target.x) * cosAngle,
                             target.y + (base.y - target.y) * cosAngle + (base.x - target.x) * sinAngle);
}


std::pair<int, int>
pointToPointRotationOffset(const Components::Point &base, float angle, const Components::Point &target) noexcept {
    const float angleInRadians = angle * M_PI / 180;
    const float sinAngle = std::sin(angleInRadians);
    const float cosAngle = std::cos(angleInRadians);

    return std::pair<int, int>((target.y - base.y) * sinAngle + (base.x - target.x) * cosAngle,
                               (base.y - target.y) * cosAngle + (base.x - target.x) * sinAngle);
}
