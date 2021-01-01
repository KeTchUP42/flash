//
// Created by roman on 26.09.2020.
//

#include "Area.h"
#include "../../math/RotatingMath.h"

#include <cmath>

Components::Area::Area(const Components::Point &point, const Components::Size &size, float angle)
        : m_angle(angle), m_point(point), m_size(size) {}

void Components::Area::move(float offsetX, float offsetY) noexcept {
    m_point.x += offsetX;
    m_point.y += offsetY;
}

void Components::Area::rotate(float angle) noexcept {
    if (std::abs(angle) >= 360) {
        float whole_part;
        float fractional_part = modff(angle, &whole_part);
        angle = static_cast<int>(whole_part) % 360 + fractional_part;
    }
    m_angle += angle;
    if (std::abs(m_angle) >= 360) {
        float whole_part;
        float fractional_part = modff(m_angle, &whole_part);
        m_angle = static_cast<int>(whole_part) % 360 + fractional_part;
    }
}

void Components::Area::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Point(x, y));
}

void Components::Area::rotate(float angle, const Components::Point &point) noexcept {
    m_point = Math::pointToPointRotation(m_point, angle, point);
    this->rotate(angle);
}

void Components::Area::setPosition(const Components::Point &point) noexcept {
    m_point = point;
}

void Components::Area::setPosition(float x, float y) noexcept {
    m_point.x = x;
    m_point.y = y;
}

void Components::Area::setSize(const Components::Size &size) noexcept {
    m_size = size;
}

void Components::Area::setRotation(float angle) noexcept {
    m_angle = 0;
    this->rotate(angle);
}

const Components::Point &Components::Area::getPosition() const noexcept {
    return m_point;
}

const Components::Size &Components::Area::getSize() const noexcept {
    return m_size;
}

float Components::Area::getRotation() const noexcept {
    return m_angle;
}
