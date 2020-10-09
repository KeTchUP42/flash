//
// Created by roman on 06.10.2020.
//

#include "InvisibleBlock.h"
#include "../../../../../../../utils/math/Rectangle.h"

Obstacles::InvisibleBlock::InvisibleBlock(const Obstacles::ObstacleProperties &properties, const Components::Area &area,
                                          const std::shared_ptr<Material::Algorithms> &algorithms)
        : Obstacle(properties), m_area(area), m_algorithms(algorithms) {}

void Obstacles::InvisibleBlock::draw(sf::RenderTarget &target) const noexcept {
    //..
}

bool Obstacles::InvisibleBlock::collision(float x, float y) const noexcept {
    return m_area.collision(x, y);
}

void Obstacles::InvisibleBlock::move(float offsetX, float offsetY) noexcept {
    m_area.move(offsetX, offsetY);
}

const Obstacles::ObstacleProperties &Obstacles::InvisibleBlock::getProperties() const noexcept {
    return m_properties;
}

const Components::Point &Obstacles::InvisibleBlock::getPosition() const noexcept {
    return m_area.m_point;
}

const Components::Size &Obstacles::InvisibleBlock::getSize() const noexcept {
    return m_area.m_size;
}

float Obstacles::InvisibleBlock::getRotation() const noexcept {
    return m_area.m_angle;
}

void Obstacles::InvisibleBlock::setPosition(const Components::Point &point) noexcept {
    m_area.setPosition(point);
}

void Obstacles::InvisibleBlock::setPosition(float x, float y) noexcept {
    m_area.setPosition(x, y);
}

void Obstacles::InvisibleBlock::setSize(const Components::Size &size) noexcept {
    m_area.setSize(size);
}

void Obstacles::InvisibleBlock::setRotation(float angle) noexcept {
    m_area.setRotation(angle);
}

void Obstacles::InvisibleBlock::rotate(float angle) noexcept {
    m_area.rotate(angle);
}

void Obstacles::InvisibleBlock::rotate(float angle, float x, float y) noexcept {
    m_area.rotate(angle, x, y);
}

void Obstacles::InvisibleBlock::rotate(float angle, const Components::Point &point) noexcept {
    m_area.rotate(angle, point);
}

void Obstacles::InvisibleBlock::addSpeed(float offsetX, float offsetY) noexcept {
    m_properties.speed.xSpeed += offsetX;
    m_properties.speed.ySpeed += offsetY;
}

void Obstacles::InvisibleBlock::setSpeed(const Components::Speed &speed) noexcept {
    m_properties.speed = speed;
}

const Components::Speed &Obstacles::InvisibleBlock::getSpeed() const noexcept {
    return m_properties.speed;
}

