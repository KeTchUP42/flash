//
// Created by roman on 17.09.2020.
//

#include "Mob.h"
#include "../../../../auxiliary/computations/CoordinatesComputations.h"

Mobs::Mob::Mob(const MobProperties &properties, const Components::Area &area, const std::shared_ptr<Components::ISpriteBox> &sprite)
        : m_area(area), m_properties(properties), m_sprite(sprite) {}

void Mobs::Mob::loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    m_sprite->setTexture(texture);
}

void Mobs::Mob::updateCoordinates() noexcept {
    //Some optimization logic. Can be changed with general movement logic update.
    if ((m_AreaDump.m_point != m_area.m_point) || (m_AreaDump.m_size != m_area.m_size) || (m_AreaDump.m_angle != m_area.m_angle)) {
        m_coordinates = Computations::coordinates(*this);
        m_AreaDump = m_area;
    } else if (m_coordinates.list.empty()) {
        m_coordinates = Computations::coordinates(*this);
    }
}

void Mobs::Mob::draw(sf::RenderTarget &target) const noexcept {
    m_sprite->draw(target);
}

void Mobs::Mob::move(float offsetX, float offsetY) noexcept {
    m_area.move(offsetX, offsetY);
    m_sprite->move(offsetX, offsetY);
}

void Mobs::Mob::rotate(float angle) noexcept {
    m_area.rotate(angle);
    m_sprite->rotate(angle);
}

void Mobs::Mob::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Components::Point(x, y));
}

void Mobs::Mob::rotate(float angle, const Components::Point &point) noexcept {
    m_area.rotate(angle, point);
    m_sprite->rotate(angle, point);
}

const Components::Point &Mobs::Mob::getPosition() const noexcept {
    return m_area.m_point;
}

const Components::Size &Mobs::Mob::getSize() const noexcept {
    return m_area.m_size;
}

float Mobs::Mob::getRotation() const noexcept {
    return m_area.m_angle;
}

void Mobs::Mob::setPosition(const Components::Point &point) noexcept {
    this->setPosition(point.x, point.y);
}

void Mobs::Mob::setPosition(float x, float y) noexcept {
    float spriteOffsetX = m_sprite->getPosition().x - m_area.m_point.x;
    float spriteOffsetY = m_sprite->getPosition().y - m_area.m_point.y;
    m_area.setPosition(x, y);
    m_sprite->setPosition(m_area.m_point.x + spriteOffsetX, m_area.m_point.y + spriteOffsetY);
}

void Mobs::Mob::setSize(const Components::Size &size) noexcept {
    float widthCoeff = static_cast<float>(m_sprite->getSize().width) / m_area.m_size.width;
    float heightCoeff = static_cast<float>(m_sprite->getSize().height) / m_area.m_size.height;
    m_area.setSize(size);
    m_sprite->setSize(Components::Size(m_area.m_size.width * widthCoeff, m_area.m_size.height * heightCoeff));
}

void Mobs::Mob::setRotation(float angle) noexcept {
    m_area.setRotation(angle);
    m_sprite->setRotation(angle);
}

const std::shared_ptr<Components::ISpriteBox> &Mobs::Mob::getSprite() const noexcept {
    return m_sprite;
}

void Mobs::Mob::addSpeed(float offsetX, float offsetY) noexcept {
    m_properties.speed.add(offsetX, offsetY);
}

void Mobs::Mob::setXSpeed(float xSpeed) noexcept {
    m_properties.speed.xSpeed = xSpeed;
}

void Mobs::Mob::setYSpeed(float ySpeed) noexcept {
    m_properties.speed.ySpeed = ySpeed;
}

void Mobs::Mob::setSpeed(const Components::Speed &speed) noexcept {
    m_properties.speed = speed;
}

const Components::Speed &Mobs::Mob::getSpeed() const noexcept {
    return m_properties.speed;
}

const Components::Area &Mobs::Mob::getPhysicalArea() const noexcept {
    return m_area;
}

const Mobs::MobProperties &Mobs::Mob::getProperties() const noexcept {
    return m_properties;
}

void Mobs::Mob::setHealthPoints(float healthPoints) noexcept {
    m_properties.healthPoints = healthPoints;
}

bool Mobs::Mob::isDead() const noexcept {
    return m_properties.healthPoints <= 0;
}

void Mobs::Mob::prejudice(float damage) noexcept {
    m_properties.healthPoints -= damage;
}

void Mobs::Mob::kill() noexcept {
    this->setHealthPoints(0);
}

