//
// Created by roman on 19.10.2020.
//

#include "Obstacle.h"

Obstacles::Obstacle::Obstacle(const Material::MaterialProperties &material_properties, const Obstacles::ObstacleProperties &properties,
                              const Components::Coordinates &coordinates)
        : Material::MaterialObject(material_properties, coordinates), m_properties(properties) {}

Obstacles::Obstacle::Obstacle(const Material::MaterialProperties &material_properties, const Obstacles::ObstacleProperties &properties)
        : Material::MaterialObject(material_properties), m_properties(properties) {}

const Obstacles::ObstacleProperties &Obstacles::Obstacle::getProperties() const noexcept {
    return m_properties;
}
