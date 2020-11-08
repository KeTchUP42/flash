//
// Created by roman on 02.11.2020.
//

#include "Block.h"
#include "../../../../auxiliary/computations/CoordinatesComputations.h"

Obstacles::Block::Block(const Obstacles::ObstacleProperties &properties, const Components::Area &area)
        : Obstacle(properties), m_area(area) {}

void Obstacles::Block::updateCoordinates() noexcept {
    //Some optimization logic. Can be changed with general movement logic update.
    if ((m_AreaDump.m_point != m_area.m_point) || (m_AreaDump.m_size != m_area.m_size) || (m_AreaDump.m_angle != m_area.m_angle)) {
        m_coordinates = Computations::coordinates(this);
        m_AreaDump = m_area;
    } else if (m_coordinates.list.empty()) {
        m_coordinates = Computations::coordinates(this);
    }
}

void Obstacles::Block::move(float offsetX, float offsetY) noexcept {
    m_area.move(offsetX, offsetY);
}

void Obstacles::Block::rotate(float angle) noexcept {
    m_area.rotate(angle);
}

void Obstacles::Block::rotate(float angle, float x, float y) noexcept {
    m_area.rotate(angle, x, y);
}

void Obstacles::Block::rotate(float angle, const Components::Point &point) noexcept {
    m_area.rotate(angle, point);
}

const Components::Point &Obstacles::Block::getPosition() const noexcept {
    return m_area.m_point;
}

const Components::Size &Obstacles::Block::getSize() const noexcept {
    return m_area.m_size;
}

float Obstacles::Block::getRotation() const noexcept {
    return m_area.m_angle;
}

void Obstacles::Block::setPosition(const Components::Point &point) noexcept {
    m_area.setPosition(point);
}

void Obstacles::Block::setPosition(float x, float y) noexcept {
    m_area.setPosition(x, y);
}

void Obstacles::Block::setSize(const Components::Size &size) noexcept {
    m_area.setSize(size);
}

void Obstacles::Block::setRotation(float angle) noexcept {
    m_area.setRotation(angle);
}
