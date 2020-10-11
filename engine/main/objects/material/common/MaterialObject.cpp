//
// Created by roman on 10.10.2020.
//

#include "MaterialObject.h"

Material::MaterialObject::MaterialObject() : m_coordinates() {}

void Material::MaterialObject::updateCoordinates() noexcept {
    //Some optimization logic. Can be changed with general movement logic update.
    if (!((this->getSpeed().xSpeed == 0) && (this->getSpeed().ySpeed == 0))) {
        m_coordinates = MathUtils::coordinates(this);
    } else if ((m_coordinates.point_1.x == m_coordinates.point_3.x) || (m_coordinates.point_1.y == m_coordinates.point_3.y)) {
        m_coordinates = MathUtils::coordinates(this);
    }
}

void Material::MaterialObject::updateLocation() noexcept {
    //Method contains all physical moving logic.
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


