//
// Created by roman on 10.10.2020.
//

#include "MaterialObject.h"
#include "collision/algorithms/collision/CommonCollisionAlgorithms.h"

Material::MaterialObject::MaterialObject(const MaterialProperties &material_properties)
        : m_coordinates(), m_material_properties(material_properties) {}

Material::MaterialObject::MaterialObject(const MaterialProperties &material_properties, const Components::Coordinates &coordinates)
        : m_coordinates(coordinates), m_material_properties(material_properties) {}

void Material::MaterialObject::updateCoordinates() noexcept {
    //..
}

void Material::MaterialObject::updateLocation() noexcept {
    //Method contains all physical moving logic.
    this->move(this->getSpeed().xSpeed, this->getSpeed().ySpeed);
}

bool Material::MaterialObject::collision(float x, float y) const noexcept {
    return Material::collision(x, y, *this);
}

bool Material::MaterialObject::collision(const Possibilities::PhysicallySituated &object) const noexcept {
    return Material::collision(*this, object);
}

void Material::MaterialObject::move(float offsetX, float offsetY) noexcept {
    for (Components::Point &point : m_coordinates.list) {
        point.x += offsetX;
        point.y += offsetY;
    }
}

void Material::MaterialObject::addSpeed(float offsetX, float offsetY) noexcept {
    m_material_properties.speed.add(offsetX, offsetY);
}

void Material::MaterialObject::setSpeed(const Components::Speed &speed) noexcept {
    m_material_properties.speed = speed;
}

void Material::MaterialObject::setXSpeed(float xSpeed) noexcept {
    m_material_properties.speed.xSpeed = xSpeed;
}

void Material::MaterialObject::setYSpeed(float ySpeed) noexcept {
    m_material_properties.speed.ySpeed = ySpeed;
}

const Components::Speed &Material::MaterialObject::getSpeed() const noexcept {
    return m_material_properties.speed;
}

const Components::Coordinates &Material::MaterialObject::getCoordinates() const noexcept {
    return m_coordinates;
}

const Material::MaterialProperties &Material::MaterialObject::getMaterialProperties() const {
    return m_material_properties;
}
