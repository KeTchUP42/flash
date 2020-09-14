//
// Created by roman on 08.09.2020.
//

#include "Point.h"

Components::Point::Point() : x(), y() {}

Components::Point::Point(float x, float y) : x(x), y(y) {}

Components::Point Components::Point::operator+(const Components::Point &right) {
    return Components::Point(x + right.x, y + right.y);
}

Components::Point Components::Point::operator-(const Components::Point &right) {
    return Components::Point(x - right.x, y - right.y);
}

Components::Point &Components::Point::operator+=(Components::Point &right) {
    *this = *this + right;
    return *this;
}

Components::Point &Components::Point::operator-=(Components::Point &right) {
    *this = *this - right;
    return *this;
}

bool Components::Point::operator==(const Components::Point &rhs) const noexcept {
    return (x == rhs.x) && (y == rhs.y);
}

bool Components::Point::operator!=(const Point &rhs) const noexcept {
    return !(rhs == *this);
}