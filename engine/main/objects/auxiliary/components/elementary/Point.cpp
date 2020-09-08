//
// Created by roman on 08.09.2020.
//

#include "Point.h"

Components::Point::Point(float x, float y) : x(x), y(y) {}

bool Components::Point::operator==(const Components::Point &rhs) const {
    return (x == rhs.x) && (y == rhs.y);
}

bool Components::Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}
