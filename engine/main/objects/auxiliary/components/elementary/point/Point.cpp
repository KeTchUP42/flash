//
// Created by roman on 08.09.2020.
//

#include "Point.h"

Components::Point::Point(float x, float y) : x(x), y(y) {}

Components::Point Components::operator+(const Point &left, const Components::Point &right) noexcept {
    return Components::Point(left.x + right.x, left.y + right.y);
}

Components::Point Components::operator-(const Point &left, const Components::Point &right) noexcept {
    return Components::Point(left.x - right.x, left.y - right.y);
}

Components::Point &Components::operator+=(Point &left, const Components::Point &right) noexcept {
    left = left + right;
    return left;
}

Components::Point &Components::operator-=(Point &left, const Components::Point &right) noexcept {
    left = left - right;
    return left;
}

bool Components::operator==(const Point &left, const Components::Point &right) noexcept {
    return (left.x == right.x) && (left.y == right.y);
}

bool Components::operator!=(const Point &left, const Point &right) noexcept {
    return !(right == left);
}