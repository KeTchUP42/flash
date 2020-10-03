//
// Created by roman on 16.09.2020.
//

#include "Rectangle.h"

#define _USE_MATH_DEFINES

#include <math.h>

MathUtils::RectangleCoordinates::RectangleCoordinates(const Components::Point &point1, const Components::Point &point2,
                                                      const Components::Point &point3, const Components::Point &point4)
        : point_1(point1), point_2(point2), point_3(point3), point_4(point4) {}


MathUtils::RectangleCoordinates MathUtils::coordinates(const Possibilities::RectangleGetters &rectangle) noexcept {
    const float angleInRadians = rectangle.getRotation() * M_PI / 180;
    const float sinAngle = std::sin(angleInRadians);
    const float cosAngle = std::cos(angleInRadians);

    float rectangleX = rectangle.getPosition().x;
    float rectangleY = rectangle.getPosition().y;

    float rectangleX2 = -sinAngle + cosAngle * rectangle.getSize().width + rectangleX;
    float rectangleY2 = cosAngle + sinAngle * rectangle.getSize().width + rectangleY;

    float rectangleX3 = -sinAngle * rectangle.getSize().height + cosAngle * rectangle.getSize().width + rectangleX;
    float rectangleY3 = cosAngle * rectangle.getSize().height + sinAngle * rectangle.getSize().width + rectangleY;

    float rectangleX4 = -sinAngle * rectangle.getSize().height + cosAngle + rectangleX;
    float rectangleY4 = cosAngle * rectangle.getSize().height + sinAngle + rectangleY;

    return MathUtils::RectangleCoordinates(Components::Point(rectangleX, rectangleY),
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

bool MathUtils::collision(const Components::Point &point, const Possibilities::RectangleGetters &rectangle) noexcept {
    MathUtils::RectangleCoordinates coordinates = MathUtils::coordinates(rectangle);

    return ((product(point.x, point.y, coordinates.point_1.x, coordinates.point_1.y, coordinates.point_2.x, coordinates.point_2.y) >= 0) &&
            (product(point.x, point.y, coordinates.point_2.x, coordinates.point_2.y, coordinates.point_3.x, coordinates.point_3.y) >= 0) &&
            (product(point.x, point.y, coordinates.point_3.x, coordinates.point_3.y, coordinates.point_4.x, coordinates.point_4.y) >= 0) &&
            (product(point.x, point.y, coordinates.point_4.x, coordinates.point_4.y, coordinates.point_1.x, coordinates.point_1.y) >= 0));
}

bool MathUtils::
collision(const Possibilities::RectangleGetters &rectangle1, const Possibilities::RectangleGetters &rectangle2) noexcept {
    MathUtils::RectangleCoordinates coordinates2 = MathUtils::coordinates(rectangle2);
    if (collision(coordinates2.point_1, rectangle1)) return true;
    if (collision(coordinates2.point_2, rectangle1)) return true;
    if (collision(coordinates2.point_3, rectangle1)) return true;
    if (collision(coordinates2.point_4, rectangle1)) return true;

    MathUtils::RectangleCoordinates coordinates1 = MathUtils::coordinates(rectangle1);
    if (collision(coordinates1.point_1, rectangle2)) return true;
    if (collision(coordinates1.point_2, rectangle2)) return true;
    if (collision(coordinates1.point_3, rectangle2)) return true;
    if (collision(coordinates1.point_4, rectangle2)) return true;
    return false;
}

Components::Point
MathUtils::pointToPointRotation(const Components::Point &base, float angle, const Components::Point &target) noexcept {
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
