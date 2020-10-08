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
    return MathUtils::collision(Components::Point(x, y), *this);
}

void Obstacles::InvisibleBlock::move(float offsetX, float offsetY) noexcept {
    m_area.point.x += offsetX;
    m_area.point.y += offsetY;
}

const Obstacles::ObstacleProperties &Obstacles::InvisibleBlock::getProperties() const noexcept {
    return m_properties;
}

const Components::Point &Obstacles::InvisibleBlock::getPosition() const noexcept {
    return m_area.point;
}

const Components::Size &Obstacles::InvisibleBlock::getSize() const noexcept {
    return m_area.size;
}

float Obstacles::InvisibleBlock::getRotation() const noexcept {
    return m_area.angle;
}

void Obstacles::InvisibleBlock::setPosition(const Components::Point &point) noexcept {
    m_area.point = point;
}

void Obstacles::InvisibleBlock::setPosition(float x, float y) noexcept {
    m_area.point = Components::Point(x, y);
}

void Obstacles::InvisibleBlock::setSize(const Components::Size &size) noexcept {
    m_area.size = size;
}

void Obstacles::InvisibleBlock::setRotation(float angle) noexcept {
    m_area.angle = angle;
}

void Obstacles::InvisibleBlock::rotate(float angle) noexcept {
    m_area.angle += angle; //Week place.
}

void Obstacles::InvisibleBlock::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Components::Point(x, y));
}

void Obstacles::InvisibleBlock::rotate(float angle, const Components::Point &point) noexcept {
    m_area.point = MathUtils::pointToPointRotation(m_area.point, angle, point);
    this->rotate(angle);
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

