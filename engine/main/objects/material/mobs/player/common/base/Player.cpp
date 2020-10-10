//
// Created by roman on 08.09.2020.
//

#include "Player.h"

Mobs::Player::Player(const Mobs::PlayerProperties &properties, const Components::Area &area, const std::shared_ptr<Components::ISpriteBox> &sprite)
        : m_properties(properties), m_area(area), m_sprite(sprite) {}

void Mobs::Player::loadKeyMap(const std::map<Mobs::KeyAlias, sf::Keyboard::Key> &keyMap) noexcept {
    m_keyMap = keyMap;
}

void Mobs::Player::loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    m_sprite->setTexture(texture);
}

void Mobs::Player::draw(sf::RenderTarget &target) const noexcept {
    m_sprite->draw(target);
}

void Mobs::Player::move(float offsetX, float offsetY) noexcept {
    m_area.move(offsetX, offsetY);
    m_sprite->move(offsetX, offsetY);
}

void Mobs::Player::rotate(float angle) noexcept {
    m_area.rotate(angle);
    m_sprite->rotate(angle);
}

void Mobs::Player::rotate(float angle, float x, float y) noexcept {
    Components::Point point(x, y);
    m_area.rotate(angle, point);
    m_sprite->rotate(angle, point);
}

void Mobs::Player::rotate(float angle, const Components::Point &point) noexcept {
    m_area.rotate(angle, point);
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
    return m_area.m_point;
}

const Components::Size &Mobs::Player::getSize() const noexcept {
    return m_area.m_size;
}

float Mobs::Player::getRotation() const noexcept {
    return m_area.m_angle;
}

const std::map<Mobs::KeyAlias, sf::Keyboard::Key> &Mobs::Player::getKeyMap() const noexcept {
    return m_keyMap;
}

const std::shared_ptr<Components::ISpriteBox> &Mobs::Player::getSprite() const noexcept {
    return m_sprite;
}

void Mobs::Player::setPosition(const Components::Point &point) noexcept {
    this->setPosition(point.x, point.y);
}

void Mobs::Player::setPosition(float x, float y) noexcept {
    float spriteOffsetX = m_sprite->getPosition().x - m_area.m_point.x;
    float spriteOffsetY = m_sprite->getPosition().y - m_area.m_point.y;
    m_area.setPosition(x, y);
    m_sprite->setPosition(m_area.m_point.x + spriteOffsetX, m_area.m_point.y + spriteOffsetY);
}

void Mobs::Player::setSize(const Components::Size &size) noexcept {
    float widthCoeff = static_cast<float>(m_sprite->getSize().width) / m_area.m_size.width;
    float heightCoeff = static_cast<float>(m_sprite->getSize().height) / m_area.m_size.height;
    m_area.setSize(size);
    m_sprite->setSize(Components::Size(m_area.m_size.width * widthCoeff, m_area.m_size.height * heightCoeff));
}

void Mobs::Player::setRotation(float angle) noexcept {
    m_area.setRotation(angle);
    m_sprite->setRotation(angle);
}
