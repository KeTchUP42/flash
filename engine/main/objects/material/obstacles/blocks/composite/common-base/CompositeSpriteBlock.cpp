//
// Created by roman on 11.09.2020.
//

#include "CompositeSpriteBlock.h"
#include "../../../../../../../utils/other/Calculations.h"

Obstacles::CompositeSpriteBlock::CompositeSpriteBlock(const Components::Point &point, const Components::Size &size,
                                                      const ObstacleProperties &properties, const std::shared_ptr<Components::ISprite> &sprite)
        : Obstacles::Obstacle(properties), _point(point), _size(size), _speed(), _sprite(sprite) {
}

void Obstacles::CompositeSpriteBlock::loadNewSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    _sprite.reset(); //Safe delete.
    _sprite = sprite;
}

bool Obstacles::CompositeSpriteBlock::collision(float x, float y) const noexcept {
    return OtherUtils::collision(Components::Point(x, y), *this) && _sprite->collision(x, y);
}

void Obstacles::CompositeSpriteBlock::draw(sf::RenderTarget &target) const noexcept {
    _sprite->draw(target);
}

void Obstacles::CompositeSpriteBlock::move(float offsetX, float offsetY) noexcept {
    _point.x += offsetX;
    _point.y += offsetY;
    _sprite->move(offsetX, offsetY);
}

void Obstacles::CompositeSpriteBlock::rotate(float angle) noexcept {
    _sprite->rotate(angle);
    _angle += angle;
}

void Obstacles::CompositeSpriteBlock::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Components::Point(x, y));
}

void Obstacles::CompositeSpriteBlock::rotate(float angle, const Components::Point &point) noexcept {
    _point = OtherUtils::pointToPointRotation(_point, angle, point);
    _sprite->rotate(angle, point);
    _angle += angle;
}

void Obstacles::CompositeSpriteBlock::addSpeed(float offsetX, float offsetY) noexcept {
    _speed.xSpeed += offsetX;
    _speed.ySpeed += offsetY;
}

void Obstacles::CompositeSpriteBlock::setMoveSpeed(const Components::Speed &speed) noexcept {
    _speed = speed;
}

const Components::Speed &Obstacles::CompositeSpriteBlock::getMoveSpeed() const noexcept {
    return _speed;
}

const Components::Point &Obstacles::CompositeSpriteBlock::getPosition() const noexcept {
    return _point;
}

const Components::Size &Obstacles::CompositeSpriteBlock::getSize() const noexcept {
    return _size;
}

float Obstacles::CompositeSpriteBlock::getRotation() const noexcept {
    return _angle;
}

float Obstacles::CompositeSpriteBlock::getElasticCoefficient() const noexcept {
    return _properties.elasticCoefficient;
}

void Obstacles::CompositeSpriteBlock::setPosition(const Components::Point &point) noexcept {
    _point = point;
}

void Obstacles::CompositeSpriteBlock::setPosition(float x, float y) noexcept {
    _point = Components::Point(x, y);
}

void Obstacles::CompositeSpriteBlock::setSize(const Components::Size &size) noexcept {
    _size = size;
}

void Obstacles::CompositeSpriteBlock::setRotation(float angle) noexcept {
    _angle = angle;
}
