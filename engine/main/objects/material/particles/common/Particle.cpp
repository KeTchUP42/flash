//
// Created by roman on 29.11.2020.
//

#include "Particle.h"

Particles::Particle::Particle(const Material::MaterialProperties &material_properties, const Particles::ParticleProperties &properties,
                              const Components::Coordinates &coordinates)
        : Material::MaterialObject(material_properties, coordinates), m_properties(properties) {}

Particles::Particle::Particle(const Material::MaterialProperties &material_properties, const Particles::ParticleProperties &properties)
        : Material::MaterialObject(material_properties), m_properties(properties) {}

const Particles::ParticleProperties &Particles::Particle::getProperties() const noexcept {
    return m_properties;
}
