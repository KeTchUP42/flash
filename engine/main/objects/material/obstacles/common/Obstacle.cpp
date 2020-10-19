//
// Created by roman on 19.10.2020.
//

#include "Obstacle.h"

Obstacles::Obstacle::Obstacle(const Obstacles::ObstacleProperties &properties) : m_properties(properties) {}

void Obstacles::Obstacle::addSpeed(float offsetX, float offsetY) noexcept {
    m_properties.speed.xSpeed += offsetX;
    m_properties.speed.ySpeed += offsetY;
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
