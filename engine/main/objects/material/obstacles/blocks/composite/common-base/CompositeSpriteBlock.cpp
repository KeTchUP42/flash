//
// Created by roman on 11.09.2020.
//

#include "CompositeSpriteBlock.h"
#include "../../../../../../../utils/other/Calculations.h"

Obstacles::CompositeSpriteBlock::CompositeSpriteBlock(const Components::Area &area, const ObstacleProperties &properties,
                                                      const std::shared_ptr<Components::ISprite> &sprite)
        : Obstacles::Obstacle(properties), _area(area), _sprite(sprite) {
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
    _area.point.x += offsetX;
    _area.point.y += offsetY;
    _sprite->move(offsetX, offsetY);
}

void Obstacles::CompositeSpriteBlock::rotate(float angle) noexcept {
    _sprite->rotate(angle);
    _area.angle += angle;
}

void Obstacles::CompositeSpriteBlock::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Components::Point(x, y));
}

void Obstacles::CompositeSpriteBlock::rotate(float angle, const Components::Point &point) noexcept {
    _area.point = OtherUtils::pointToPointRotation(_area.point, angle, point);
    _sprite->rotate(angle, point);
    _area.angle += angle;
}

void Obstacles::CompositeSpriteBlock::addSpeed(float offsetX, float offsetY) noexcept {
    _properties.speed.xSpeed += offsetX;
    _properties.speed.ySpeed += offsetY;
}

void Obstacles::CompositeSpriteBlock::setMoveSpeed(const Components::Speed &speed) noexcept {
    _properties.speed = speed;
}

const Components::Speed &Obstacles::CompositeSpriteBlock::getMoveSpeed() const noexcept {
    return _properties.speed;
}

const Components::Point &Obstacles::CompositeSpriteBlock::getPosition() const noexcept {
    return _area.point;
}

const Components::Size &Obstacles::CompositeSpriteBlock::getSize() const noexcept {
    return _area.size;
}

float Obstacles::CompositeSpriteBlock::getRotation() const noexcept {
    return _area.angle;
}

const Material::MaterialObjectProperties &Obstacles::CompositeSpriteBlock::getProperties() const noexcept {
    return _properties;
}

void Obstacles::CompositeSpriteBlock::setPosition(const Components::Point &point) noexcept {
    _area.point = point;
}

void Obstacles::CompositeSpriteBlock::setPosition(float x, float y) noexcept {
    _area.point = Components::Point(x, y);
}

void Obstacles::CompositeSpriteBlock::setSize(const Components::Size &size) noexcept {
    _area.size = size;
}

void Obstacles::CompositeSpriteBlock::setRotation(float angle) noexcept {
    _area.angle = angle;
}
