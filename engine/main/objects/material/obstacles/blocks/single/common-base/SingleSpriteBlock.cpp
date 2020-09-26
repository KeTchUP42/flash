//
// Created by roman on 11.09.2020.
//

#include "SingleSpriteBlock.h"

Obstacles::SingleSpriteBlock::SingleSpriteBlock(const Obstacles::ObstacleProperties &properties,
                                                const std::shared_ptr<Components::ISpriteBox> &sprite,
                                                const std::shared_ptr<Material::Collision> &collision)
        : Obstacles::Obstacle(properties), _sprite(sprite), _collision(collision) {}

void Obstacles::SingleSpriteBlock::loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    _sprite->setTexture(texture);
}

bool Obstacles::SingleSpriteBlock::collision(float x, float y) const noexcept {
    return _sprite->collision(x, y);
}

void Obstacles::SingleSpriteBlock::draw(sf::RenderTarget &target) const noexcept {
    _sprite->draw(target);
}

void Obstacles::SingleSpriteBlock::move(float offsetX, float offsetY) noexcept {
    _sprite->move(offsetX, offsetY);
}

void Obstacles::SingleSpriteBlock::rotate(float angle) noexcept {
    _sprite->rotate(angle);
}

void Obstacles::SingleSpriteBlock::rotate(float angle, float x, float y) noexcept {
    _sprite->rotate(angle, x, y);
}

void Obstacles::SingleSpriteBlock::rotate(float angle, const Components::Point &point) noexcept {
    _sprite->rotate(angle, point);
}

void Obstacles::SingleSpriteBlock::addSpeed(float offsetX, float offsetY) noexcept {
    _properties.speed.xSpeed += offsetX;
    _properties.speed.ySpeed += offsetY;
}

void Obstacles::SingleSpriteBlock::setMoveSpeed(const Components::Speed &speed) noexcept {
    _properties.speed = speed;
}

const Components::Speed &Obstacles::SingleSpriteBlock::getMoveSpeed() const noexcept {
    return _properties.speed;
}

const Components::Point &Obstacles::SingleSpriteBlock::getPosition() const noexcept {
    return _sprite->getPosition();
}

const Components::Size &Obstacles::SingleSpriteBlock::getSize() const noexcept {
    return _sprite->getSize();
}

float Obstacles::SingleSpriteBlock::getRotation() const noexcept {
    return _sprite->getRotation();
}

const Obstacles::ObstacleProperties &Obstacles::SingleSpriteBlock::getProperties() const noexcept {
    return _properties;
}

void Obstacles::SingleSpriteBlock::setPosition(const Components::Point &point) noexcept {
    _sprite->setPosition(point);
}

void Obstacles::SingleSpriteBlock::setPosition(float x, float y) noexcept {
    _sprite->setPosition(Components::Point(x, y));
}

void Obstacles::SingleSpriteBlock::setSize(const Components::Size &size) noexcept {
    _sprite->setSize(size);
}

void Obstacles::SingleSpriteBlock::setRotation(float angle) noexcept {
    _sprite->setRotation(angle);
}
