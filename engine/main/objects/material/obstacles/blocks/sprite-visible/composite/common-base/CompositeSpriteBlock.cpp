//
// Created by roman on 11.09.2020.
//

#include "CompositeSpriteBlock.h"
#include "../../../../../../../../utils/math/Rectangle.h"

Obstacles::CompositeSpriteBlock::CompositeSpriteBlock(const Components::Area &area, const ObstacleProperties &properties,
                                                      const std::shared_ptr<Components::ISprite> &sprite, const std::shared_ptr<Material::Algorithms> &algorithms)
        : Obstacles::Obstacle(properties), m_area(area), m_sprite(sprite), m_algorithms(algorithms) {
}

void Obstacles::CompositeSpriteBlock::loadNewSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    m_sprite.reset(); //Safe delete.
    m_sprite = sprite;
}

bool Obstacles::CompositeSpriteBlock::collision(float x, float y) const noexcept {
    return MathUtils::collision(Components::Point(x, y), *this) && m_sprite->collision(x, y);
}

void Obstacles::CompositeSpriteBlock::draw(sf::RenderTarget &target) const noexcept {
    m_sprite->draw(target);
}

void Obstacles::CompositeSpriteBlock::move(float offsetX, float offsetY) noexcept {
    m_area.point.x += offsetX;
    m_area.point.y += offsetY;
    m_sprite->move(offsetX, offsetY);
}

void Obstacles::CompositeSpriteBlock::rotate(float angle) noexcept {
    m_sprite->rotate(angle);
    m_area.angle += angle; //Week place.
}

void Obstacles::CompositeSpriteBlock::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Components::Point(x, y));
}

void Obstacles::CompositeSpriteBlock::rotate(float angle, const Components::Point &point) noexcept {
    m_area.point = MathUtils::pointToPointRotation(m_area.point, angle, point);
    m_sprite->rotate(angle, point);
    m_area.angle += angle; //Week place.
}

void Obstacles::CompositeSpriteBlock::addSpeed(float offsetX, float offsetY) noexcept {
    m_properties.speed.xSpeed += offsetX;
    m_properties.speed.ySpeed += offsetY;
}

void Obstacles::CompositeSpriteBlock::setMoveSpeed(const Components::Speed &speed) noexcept {
    m_properties.speed = speed;
}

const Components::Speed &Obstacles::CompositeSpriteBlock::getMoveSpeed() const noexcept {
    return m_properties.speed;
}

const Components::Point &Obstacles::CompositeSpriteBlock::getPosition() const noexcept {
    return m_area.point;
}

const Components::Size &Obstacles::CompositeSpriteBlock::getSize() const noexcept {
    return m_area.size;
}

float Obstacles::CompositeSpriteBlock::getRotation() const noexcept {
    return m_area.angle;
}

const Obstacles::ObstacleProperties &Obstacles::CompositeSpriteBlock::getProperties() const noexcept {
    return m_properties;
}

void Obstacles::CompositeSpriteBlock::setPosition(const Components::Point &point) noexcept {
    m_area.point = point;
}

void Obstacles::CompositeSpriteBlock::setPosition(float x, float y) noexcept {
    m_area.point = Components::Point(x, y);
}

void Obstacles::CompositeSpriteBlock::setSize(const Components::Size &size) noexcept {
    m_area.size = size;
}

void Obstacles::CompositeSpriteBlock::setRotation(float angle) noexcept {
    m_area.angle = angle;
}
