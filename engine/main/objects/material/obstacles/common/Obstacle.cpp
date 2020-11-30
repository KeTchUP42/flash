//
// Created by roman on 19.10.2020.
//

#include "Obstacle.h"

Obstacles::Obstacle::Obstacle(const Obstacles::ObstacleProperties &properties, const Components::Coordinates &coordinates)
        : Material::MaterialObject(coordinates), m_properties(properties) {}

Obstacles::Obstacle::Obstacle(const Obstacles::ObstacleProperties &properties) : m_properties(properties) {}

void Obstacles::Obstacle::addSpeed(float offsetX, float offsetY) noexcept {
    m_properties.speed.add(offsetX, offsetY);
}

void Obstacles::Obstacle::setXSpeed(float xSpeed) noexcept {
    m_properties.speed.xSpeed = xSpeed;
}

void Obstacles::Obstacle::setYSpeed(float ySpeed) noexcept {
    m_properties.speed.ySpeed = ySpeed;
}

void Obstacles::Obstacle::setSpeed(const Components::Speed &speed) noexcept {
    m_properties.speed = speed;
}

const Components::Speed &Obstacles::Obstacle::getSpeed() const noexcept {
    return m_properties.speed;
}

const Obstacles::ObstacleProperties &Obstacles::Obstacle::getProperties() const noexcept {
    return m_properties;
}
