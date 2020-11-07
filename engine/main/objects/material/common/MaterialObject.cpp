//
// Created by roman on 10.10.2020.
//

#include "MaterialObject.h"
#include "collision/algorithms/collision/CommonCollisionAlgorithms.h"

Material::MaterialObject::MaterialObject() : m_coordinates() {}

Material::MaterialObject::MaterialObject(const Components::Coordinates &coordinates) : m_coordinates(coordinates) {}

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

const Components::Coordinates &Material::MaterialObject::getCoordinates() const noexcept {
    return m_coordinates;
}



