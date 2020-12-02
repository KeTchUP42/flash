//
// Created by roman on 16.09.2020.
//

#include "CoordinatesComputations.h"

#define _USE_MATH_DEFINES

#include <math.h>

Components::Coordinates Calculations::coordinates(Possibilities::RectangleGetters &rectangle) noexcept {
    //The angle is expected to be with a pre-rounded degree.
    if (rectangle.getRotation() == 0) {
        return Components::Coordinates(
                std::vector<Components::Point>{
                        Components::Point(rectangle.getPosition().x, rectangle.getPosition().y),
                        Components::Point(rectangle.getPosition().x + rectangle.getSize().width, rectangle.getPosition().y),
                        Components::Point(rectangle.getPosition().x + rectangle.getSize().width, rectangle.getPosition().y + rectangle.getSize().height),
                        Components::Point(rectangle.getPosition().x, rectangle.getPosition().y + rectangle.getSize().height)
                });
    }

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

    return Components::Coordinates(
            std::vector<Components::Point>{
                    Components::Point(rectangleX, rectangleY),
                    Components::Point(rectangleX2, rectangleY2),
                    Components::Point(rectangleX3, rectangleY3),
                    Components::Point(rectangleX4, rectangleY4)
            });
}
