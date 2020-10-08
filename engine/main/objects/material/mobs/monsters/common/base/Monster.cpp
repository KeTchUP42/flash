//
// Created by roman on 17.09.2020.
//

#include "Monster.h"

Mobs::Monster::Monster(const Mobs::MonsterProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite)
        : m_properties(properties), m_sprite(sprite) {}

void Mobs::Monster::loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    m_sprite->setTexture(texture);
}

bool Mobs::Monster::collision(float x, float y) const noexcept {
    return m_sprite->collision(x, y);
}

void Mobs::Monster::draw(sf::RenderTarget &target) const noexcept {
    m_sprite->draw(target);
}

void Mobs::Monster::move(float offsetX, float offsetY) noexcept {
    m_sprite->move(offsetX, offsetY);
}

void Mobs::Monster::rotate(float angle) noexcept {
    m_sprite->rotate(angle);
}

void Mobs::Monster::rotate(float angle, float x, float y) noexcept {
    m_sprite->rotate(angle, x, y);
}

void Mobs::Monster::rotate(float angle, const Components::Point &point) noexcept {
    m_sprite->rotate(angle, point);
}

void Mobs::Monster::addSpeed(float offsetX, float offsetY) noexcept {
    m_properties.speed.xSpeed += offsetX;
    m_properties.speed.ySpeed += offsetY;
}

void Mobs::Monster::setSpeed(const Components::Speed &speed) noexcept {
    m_properties.speed = speed;
}

const Components::Speed &Mobs::Monster::getSpeed() const noexcept {
    return m_properties.speed;
}

const Components::Point &Mobs::Monster::getPosition() const noexcept {
    return m_sprite->getPosition();
}

const Components::Size &Mobs::Monster::getSize() const noexcept {
    return m_sprite->getSize();
}

float Mobs::Monster::getRotation() const noexcept {
    return m_sprite->getRotation();
}

void Mobs::Monster::setPosition(const Components::Point &point) noexcept {
    m_sprite->setPosition(point);
}

void Mobs::Monster::setPosition(float x, float y) noexcept {
    m_sprite->setPosition(Components::Point(x, y));
}

void Mobs::Monster::setSize(const Components::Size &size) noexcept {
    m_sprite->setSize(size);
}

void Mobs::Monster::setRotation(float angle) noexcept {
    m_sprite->setRotation(angle);
}

const std::shared_ptr<Components::ISpriteBox> &Mobs::Monster::getSprite() const noexcept {
    return m_sprite;
}

const Mobs::MonsterProperties &Mobs::Monster::getProperties() const noexcept {
    return m_properties;
}
