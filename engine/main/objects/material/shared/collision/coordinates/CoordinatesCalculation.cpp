//
// Created by roman on 18.09.2020.
//

#include "CoordinatesCalculation.h"

#define _USE_MATH_DEFINES

#include <math.h>
#include <algorithm>

Components::Point Material::maxCoordinates(const Possibilities::RectangleGetters &rectangle) {
    const float rectangleAngleInRadians = rectangle.getRotation() * M_PI / 180;
    const float sinAngle = std::sin(rectangleAngleInRadians);
    const float cosAngle = std::cos(rectangleAngleInRadians);

    const float rectangleXStart = rectangle.getPosition().x;

    float rectangleX2 = -sinAngle + cosAngle * rectangle.getSize().width + rectangleXStart;
    float rectangleX3 = -sinAngle * rectangle.getSize().height + cosAngle * rectangle.getSize().width + rectangleXStart;
    float rectangleX4 = -sinAngle * rectangle.getSize().height + cosAngle + rectangleXStart;

    const float rectangleYStart = rectangle.getPosition().y;

    float rectangleY2 = cosAngle + sinAngle * rectangle.getSize().width + rectangleYStart;
    float rectangleY3 = cosAngle * rectangle.getSize().height + sinAngle * rectangle.getSize().width + rectangleYStart;
    float rectangleY4 = cosAngle * rectangle.getSize().height + sinAngle + rectangleYStart;

    return Components::Point(std::max(std::max(rectangleX2, rectangleX3), std::max(rectangleX4, rectangleXStart)),
                             std::max(std::max(rectangleY2, rectangleY3), std::max(rectangleY4, rectangleYStart)));
}

Components::Point Material::minCoordinates(const Possibilities::RectangleGetters &rectangle) {
    const float rectangleAngleInRadians = rectangle.getRotation() * M_PI / 180;
    const float sinAngle = std::sin(rectangleAngleInRadians);
    const float cosAngle = std::cos(rectangleAngleInRadians);

    const float rectangleXStart = rectangle.getPosition().x;

    float rectangleX2 = -sinAngle + cosAngle * rectangle.getSize().width + rectangleXStart;
    float rectangleX3 = -sinAngle * rectangle.getSize().height + cosAngle * rectangle.getSize().width + rectangleXStart;
    float rectangleX4 = -sinAngle * rectangle.getSize().height + cosAngle + rectangleXStart;

    const float rectangleYStart = rectangle.getPosition().y;

    float rectangleY2 = cosAngle + sinAngle * rectangle.getSize().width + rectangleYStart;
    float rectangleY3 = cosAngle * rectangle.getSize().height + sinAngle * rectangle.getSize().width + rectangleYStart;
    float rectangleY4 = cosAngle * rectangle.getSize().height + sinAngle + rectangleYStart;

    return Components::Point(std::min(std::min(rectangleX2, rectangleX3), std::min(rectangleX4, rectangleXStart)),
                             std::min(std::min(rectangleY2, rectangleY3), std::min(rectangleY4, rectangleYStart)));
}
