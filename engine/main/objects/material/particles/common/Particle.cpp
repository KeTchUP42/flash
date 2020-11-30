//
// Created by roman on 29.11.2020.
//

#include "Particle.h"

Particles::Particle::Particle(const Particles::ParticleProperties &properties, const Components::Coordinates &coordinates)
        : Material::MaterialObject(coordinates), m_properties(properties) {}

Particles::Particle::Particle(const Particles::ParticleProperties &properties) : m_properties(properties) {}

void Particles::Particle::addSpeed(float offsetX, float offsetY) noexcept {
    m_properties.speed.add(offsetX, offsetY);
}

void Particles::Particle::setXSpeed(float xSpeed) noexcept {
    m_properties.speed.xSpeed = xSpeed;
}

void Particles::Particle::setYSpeed(float ySpeed) noexcept {
    m_properties.speed.ySpeed = ySpeed;
}

void Particles::Particle::setSpeed(const Components::Speed &speed) noexcept {
    m_properties.speed = speed;
}

const Components::Speed &Particles::Particle::getSpeed() const noexcept {
    return m_properties.speed;
}

const Particles::ParticleProperties &Particles::Particle::getProperties() const noexcept {
    return m_properties;
}
