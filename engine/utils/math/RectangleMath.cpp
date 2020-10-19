//
// Created by roman on 16.09.2020.
//

#include "RectangleMath.h"

#define _USE_MATH_DEFINES

#include <math.h>

Components::Coordinates MathUtils::coordinates(Possibilities::RectangleInfo *rectangle) noexcept {
    //Conditional expected for pre-rounded degrees.
    if (rectangle->getRotation() == 0) {
        return Components::Coordinates(
                Components::Point(rectangle->getPosition().x, rectangle->getPosition().y),
                Components::Point(rectangle->getPosition().x + rectangle->getSize().width, rectangle->getPosition().y),
                Components::Point(rectangle->getPosition().x + rectangle->getSize().width, rectangle->getPosition().y + rectangle->getSize().height),
                Components::Point(rectangle->getPosition().x, rectangle->getPosition().y + rectangle->getSize().height));
    }

    const float angleInRadians = rectangle->getRotation() * M_PI / 180;
    const float sinAngle = std::sin(angleInRadians);
    const float cosAngle = std::cos(angleInRadians);

    float rectangleX = rectangle->getPosition().x;
    float rectangleY = rectangle->getPosition().y;

    float rectangleX2 = -sinAngle + cosAngle * rectangle->getSize().width + rectangleX;
    float rectangleY2 = cosAngle + sinAngle * rectangle->getSize().width + rectangleY;

    float rectangleX3 = -sinAngle * rectangle->getSize().height + cosAngle * rectangle->getSize().width + rectangleX;
    float rectangleY3 = cosAngle * rectangle->getSize().height + sinAngle * rectangle->getSize().width + rectangleY;

    float rectangleX4 = -sinAngle * rectangle->getSize().height + cosAngle + rectangleX;
    float rectangleY4 = cosAngle * rectangle->getSize().height + sinAngle + rectangleY;

    return Components::Coordinates(Components::Point(rectangleX, rectangleY), Components::Point(rectangleX2, rectangleY2),
                                   Components::Point(rectangleX3, rectangleY3), Components::Point(rectangleX4, rectangleY4));
}

/**
 * @brief This is help function for collision function.
 * @return The value responsible for the position of the point relative to the vector.
 */
static inline int product(float Px, float Py, float Ax, float Ay, float Bx, float By) {
    return (Bx - Ax) * (Py - Ay) - (By - Ay) * (Px - Ax);
}

bool MathUtils::collision(float x, float y, const Possibilities::RectangleInfo &rectangle) noexcept {
    return ((product(x, y, rectangle.getCoordinates().point_1.x, rectangle.getCoordinates().point_1.y, rectangle.getCoordinates().point_2.x, rectangle.getCoordinates().point_2.y) >= 0) &&
            (product(x, y, rectangle.getCoordinates().point_2.x, rectangle.getCoordinates().point_2.y, rectangle.getCoordinates().point_3.x, rectangle.getCoordinates().point_3.y) >= 0) &&
            (product(x, y, rectangle.getCoordinates().point_3.x, rectangle.getCoordinates().point_3.y, rectangle.getCoordinates().point_4.x, rectangle.getCoordinates().point_4.y) >= 0) &&
            (product(x, y, rectangle.getCoordinates().point_4.x, rectangle.getCoordinates().point_4.y, rectangle.getCoordinates().point_1.x, rectangle.getCoordinates().point_1.y) >= 0));
}

bool MathUtils::collision(const Components::Point &point, const Possibilities::RectangleInfo &rectangle) noexcept {
    return collision(point.x, point.y, rectangle);
}

bool MathUtils::collision(const Possibilities::RectangleInfo &rectangle1, const Possibilities::RectangleInfo &rectangle2) noexcept {

    float rectangle1Diagonal = std::sqrt(std::pow(rectangle1.getSize().width, 2) + std::pow(rectangle1.getSize().height, 2));
    float rectangle2Diagonal = std::sqrt(std::pow(rectangle2.getSize().width, 2) + std::pow(rectangle2.getSize().height, 2));

    float vectorModule = std::sqrt(std::pow(rectangle1.getPosition().x - rectangle2.getPosition().x, 2) +
                                   std::pow(rectangle1.getPosition().y - rectangle2.getPosition().y, 2));

    if (vectorModule > (rectangle1Diagonal + rectangle2Diagonal)) return false;

    if (collision(rectangle2.getCoordinates().point_1, rectangle1)) return true;
    if (collision(rectangle2.getCoordinates().point_2, rectangle1)) return true;
    if (collision(rectangle2.getCoordinates().point_3, rectangle1)) return true;
    if (collision(rectangle2.getCoordinates().point_4, rectangle1)) return true;

    if (collision(rectangle1.getCoordinates().point_1, rectangle2)) return true;
    if (collision(rectangle1.getCoordinates().point_2, rectangle2)) return true;
    if (collision(rectangle1.getCoordinates().point_3, rectangle2)) return true;
    if (collision(rectangle1.getCoordinates().point_4, rectangle2)) return true;
    return false;
}

Components::Point
MathUtils::pointToPointRotation(const Components::Point &base, float angle, const Components::Point &target) noexcept {
    float angleInRadians = angle * M_PI / 180;
    float sinAngle = std::sin(angleInRadians);
    float cosAngle = std::cos(angleInRadians);

    return Components::Point(target.x + (target.y - base.y) * sinAngle + (base.x - target.x) * cosAngle,
                             target.y + (base.y - target.y) * cosAngle + (base.x - target.x) * sinAngle);
}

std::pair<int, int>
pointToPointRotationOffset(const Components::Point &base, float angle, const Components::Point &target) noexcept {
    float angleInRadians = angle * M_PI / 180;
    float sinAngle = std::sin(angleInRadians);
    float cosAngle = std::cos(angleInRadians);

    return std::pair<int, int>((target.y - base.y) * sinAngle + (base.x - target.x) * cosAngle,
                               (base.y - target.y) * cosAngle + (base.x - target.x) * sinAngle);
}
