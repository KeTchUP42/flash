//
// Created by roman on 10.10.2020.
//

#include "MaterialObject.h"

Material::MaterialObject::MaterialObject() : m_coordinates() {};

void Material::MaterialObject::updateCoordinates() noexcept {
    m_coordinates = MathUtils::coordinates(this);
}

void Material::MaterialObject::updateLocation() noexcept {
    this->move(this->getSpeed().xSpeed, this->getSpeed().ySpeed);
}

const Components::Coordinates &Material::MaterialObject::getCoordinates() const noexcept {
    return m_coordinates;
}

bool Material::MaterialObject::collision(float x, float y) const noexcept {
    return MathUtils::collision(x, y, *this);
}

void Material::MaterialObject::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}


