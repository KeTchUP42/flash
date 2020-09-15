//
// Created by roman on 11.09.2020.
//

#include <math.h>
#include "CompositeSpriteBlock.h"

Obstacles::CompositeSpriteBlock::CompositeSpriteBlock(const Components::Point &point, const Components::Size &size,
                                                      const std::shared_ptr<Components::ISprite> &sprite)
        : _point(point), _size(size), _speed(), _sprite(sprite) {
}

void Obstacles::CompositeSpriteBlock::loadNewSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    _sprite.reset(); //Safe delete.
    _sprite = sprite;
}

bool Obstacles::CompositeSpriteBlock::collision(float x, float y) const noexcept {
    return ((x >= _point.x) && (x <= _point.x + _size.width) &&
            (y >= _point.y) && (y <= _point.y + _size.height)) &&
           _sprite->collision(x, y);
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
}

void Obstacles::CompositeSpriteBlock::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Components::Point(x, y));
}

void Obstacles::CompositeSpriteBlock::rotate(float angle, const Components::Point &point) noexcept {
    float angleInRadians = angle * M_PI / 180;
    _point.x = point.x + (point.y - _point.y) * std::sin(angleInRadians) + (_point.x - point.x) * std::cos(angleInRadians);
    _point.y = point.y + (_point.y - point.y) * std::cos(angleInRadians) + (_point.x - point.x) * std::sin(angleInRadians);
    _sprite->rotate(angle, point);
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
