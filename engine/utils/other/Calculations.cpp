//
// Created by roman on 16.09.2020.
//

#include "Calculations.h"

#define _USE_MATH_DEFINES

#include <math.h>

OtherUtils::RectangleCoordinates::RectangleCoordinates(const Components::Point &point1, const Components::Point &point2,
                                                       const Components::Point &point3, const Components::Point &point4)
        : point_1(point1), point_2(point2), point_3(point3), point_4(point4) {}


OtherUtils::RectangleCoordinates OtherUtils::coordinates(const Possibilities::RectangleGetters &rectangle) noexcept {
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

    return OtherUtils::RectangleCoordinates(Components::Point(rectangleX, rectangleY),
                                            Components::Point(rectangleX2, rectangleY2),
                                            Components::Point(rectangleX3, rectangleY3),
                                            Components::Point(rectangleX4, rectangleY4));
}

/**
 * @brief This is help function for collision function.
 * @return The value responsible for the position of the point relative to the vector.
 */
static inline int product(float Px, float Py, float Ax, float Ay, float Bx, float By) {
    return (Bx - Ax) * (Py - Ay) - (By - Ay) * (Px - Ax);
}

bool OtherUtils::collision(const Components::Point &point, const Possibilities::RectangleGetters &rectangle) noexcept {
    OtherUtils::RectangleCoordinates coordinates = OtherUtils::coordinates(rectangle);

    return ((product(point.x, point.y, coordinates.point_1.x, coordinates.point_1.y, coordinates.point_2.x, coordinates.point_2.y) >= 0) &&
            (product(point.x, point.y, coordinates.point_2.x, coordinates.point_2.y, coordinates.point_3.x, coordinates.point_3.y) >= 0) &&
            (product(point.x, point.y, coordinates.point_3.x, coordinates.point_3.y, coordinates.point_4.x, coordinates.point_4.y) >= 0) &&
            (product(point.x, point.y, coordinates.point_4.x, coordinates.point_4.y, coordinates.point_1.x, coordinates.point_1.y) >= 0));
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
