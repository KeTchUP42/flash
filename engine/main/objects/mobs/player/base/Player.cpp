//
// Created by roman on 08.09.2020.
//

#include "Player.h"

Mobs::Player::Player(const std::shared_ptr<Components::ISpriteBox> &sprite)
        : _sprite(sprite), _speed() {}

void Mobs::Player::loadKeyMap(const std::map<Mobs::KeyAlias, sf::Keyboard::Key> &keyMap) noexcept {
    _keyMap = keyMap;
}

void Mobs::Player::loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    _sprite->setTexture(texture);
}

bool Mobs::Player::collision(float x, float y) const noexcept {
    return _sprite->collision(x, y);
}

void Mobs::Player::draw(sf::RenderTarget &target) const noexcept {
    _sprite->draw(target);
}

void Mobs::Player::move(float offsetX, float offsetY) noexcept {
    _sprite->move(offsetX, offsetY);
}

void Mobs::Player::rotate(float angle) noexcept {
    _sprite->rotate(angle);
}

void Mobs::Player::rotate(float angle, float x, float y) noexcept {
    _sprite->rotate(angle, x, y);
}

void Mobs::Player::rotate(float angle, const Components::Point &point) noexcept {
    _sprite->rotate(angle, point);
}

void Mobs::Player::addSpeed(float offsetX, float offsetY) noexcept {
    _speed.xSpeed += offsetX;
    _speed.ySpeed += offsetY;
}

void Mobs::Player::setMoveSpeed(const Components::Speed &speed) noexcept {
    _speed = speed;
}

const Components::Speed &Mobs::Player::getMoveSpeed() const noexcept {
    return _speed;
}

const Components::Point &Mobs::Player::getPosition() const noexcept {
    return _sprite->getPosition();
}

const Components::Size &Mobs::Player::getSize() const noexcept {
    return _sprite->getSize();
}

float Mobs::Player::getRotation() const noexcept {
    return _sprite->getRotation();
}
