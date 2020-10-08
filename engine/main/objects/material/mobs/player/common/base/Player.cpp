//
// Created by roman on 08.09.2020.
//

#include "Player.h"

Mobs::Player::Player(const Mobs::PlayerProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite)
        : m_properties(properties), m_sprite(sprite) {}

void Mobs::Player::loadKeyMap(const std::map<Mobs::KeyAlias, sf::Keyboard::Key> &keyMap) noexcept {
    m_keyMap = keyMap;
}

void Mobs::Player::loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    m_sprite->setTexture(texture);
}

bool Mobs::Player::collision(float x, float y) const noexcept {
    return m_sprite->collision(x, y);
}

void Mobs::Player::draw(sf::RenderTarget &target) const noexcept {
    m_sprite->draw(target);
}

void Mobs::Player::move(float offsetX, float offsetY) noexcept {
    m_sprite->move(offsetX, offsetY);
}

void Mobs::Player::rotate(float angle) noexcept {
    m_sprite->rotate(angle);
}

void Mobs::Player::rotate(float angle, float x, float y) noexcept {
    m_sprite->rotate(angle, x, y);
}

void Mobs::Player::rotate(float angle, const Components::Point &point) noexcept {
    m_sprite->rotate(angle, point);
}

void Mobs::Player::addSpeed(float offsetX, float offsetY) noexcept {
    m_properties.speed.xSpeed += offsetX;
    m_properties.speed.ySpeed += offsetY;
}

void Mobs::Player::setSpeed(const Components::Speed &speed) noexcept {
    m_properties.speed = speed;
}

const Mobs::PlayerProperties &Mobs::Player::getProperties() const noexcept {
    return m_properties;
}

const Components::Speed &Mobs::Player::getSpeed() const noexcept {
    return m_properties.speed;
}

const Components::Point &Mobs::Player::getPosition() const noexcept {
    return m_sprite->getPosition();
}

const Components::Size &Mobs::Player::getSize() const noexcept {
    return m_sprite->getSize();
}

float Mobs::Player::getRotation() const noexcept {
    return m_sprite->getRotation();
}

const std::map<Mobs::KeyAlias, sf::Keyboard::Key> &Mobs::Player::getKeyMap() const noexcept {
    return m_keyMap;
}

const std::shared_ptr<Components::ISpriteBox> &Mobs::Player::getSprite() const noexcept {
    return m_sprite;
}

void Mobs::Player::setPosition(const Components::Point &point) noexcept {
    m_sprite->setPosition(point);
}

void Mobs::Player::setPosition(float x, float y) noexcept {
    m_sprite->setPosition(Components::Point(x, y));
}

void Mobs::Player::setSize(const Components::Size &size) noexcept {
    m_sprite->setSize(size);
}

void Mobs::Player::setRotation(float angle) noexcept {
    m_sprite->setRotation(angle);
}
