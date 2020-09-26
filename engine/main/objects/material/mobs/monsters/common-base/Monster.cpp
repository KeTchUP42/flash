//
// Created by roman on 17.09.2020.
//

#include "Monster.h"

Mobs::Monster::Monster(const Mobs::MonsterProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite)
        : _sprite(sprite), _properties(properties) {}

void Mobs::Monster::loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    _sprite->setTexture(texture);
}

bool Mobs::Monster::collision(float x, float y) const noexcept {
    return _sprite->collision(x, y);
}

void Mobs::Monster::draw(sf::RenderTarget &target) const noexcept {
    _sprite->draw(target);
}

void Mobs::Monster::move(float offsetX, float offsetY) noexcept {
    _sprite->move(offsetX, offsetY);
}

void Mobs::Monster::rotate(float angle) noexcept {
    _sprite->rotate(angle);
}

void Mobs::Monster::rotate(float angle, float x, float y) noexcept {
    _sprite->rotate(angle, x, y);
}

void Mobs::Monster::rotate(float angle, const Components::Point &point) noexcept {
    _sprite->rotate(angle, point);
}

void Mobs::Monster::addSpeed(float offsetX, float offsetY) noexcept {
    _properties.speed.xSpeed += offsetX;
    _properties.speed.ySpeed += offsetY;
}

void Mobs::Monster::setMoveSpeed(const Components::Speed &speed) noexcept {
    _properties.speed = speed;
}

const Components::Speed &Mobs::Monster::getMoveSpeed() const noexcept {
    return _properties.speed;
}

const Components::Point &Mobs::Monster::getPosition() const noexcept {
    return _sprite->getPosition();
}

const Components::Size &Mobs::Monster::getSize() const noexcept {
    return _sprite->getSize();
}

float Mobs::Monster::getRotation() const noexcept {
    return _sprite->getRotation();
}

const std::shared_ptr<Components::ISpriteBox> &Mobs::Monster::getSprite() const noexcept {
    return _sprite;
}

const Mobs::MonsterProperties &Mobs::Monster::getProperties() const noexcept {
    return _properties;
}
