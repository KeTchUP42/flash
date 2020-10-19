//
// Created by roman on 11.09.2020.
//

#include "CompositeSpriteBlock.h"

Obstacles::CompositeSpriteBlock::
CompositeSpriteBlock(const ObstacleProperties &properties, const Components::Area &area,
                     const std::shared_ptr<Components::ISprite> &sprite, const std::shared_ptr<Material::Algorithms> &algorithms)
        : Obstacles::Obstacle(properties), m_area(area), m_sprite(sprite), m_algorithms(algorithms) {
}

void Obstacles::CompositeSpriteBlock::loadNewSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    m_sprite.reset(); //Safe delete.
    m_sprite = sprite;
}

void Obstacles::CompositeSpriteBlock::draw(sf::RenderTarget &target) const noexcept {
    m_sprite->draw(target);
}

void Obstacles::CompositeSpriteBlock::move(float offsetX, float offsetY) noexcept {
    m_area.move(offsetX, offsetY);
    m_sprite->move(offsetX, offsetY);
}

void Obstacles::CompositeSpriteBlock::rotate(float angle) noexcept {
    m_area.rotate(angle);
    m_sprite->rotate(angle);
}

void Obstacles::CompositeSpriteBlock::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Components::Point(x, y));
}

void Obstacles::CompositeSpriteBlock::rotate(float angle, const Components::Point &point) noexcept {
    m_area.rotate(angle, point);
    m_sprite->rotate(angle, point);
}

const Components::Point &Obstacles::CompositeSpriteBlock::getPosition() const noexcept {
    return m_area.m_point;
}

const Components::Size &Obstacles::CompositeSpriteBlock::getSize() const noexcept {
    return m_area.m_size;
}

float Obstacles::CompositeSpriteBlock::getRotation() const noexcept {
    return m_area.m_angle;
}

void Obstacles::CompositeSpriteBlock::setPosition(const Components::Point &point) noexcept {
    m_area.setPosition(point);
}

void Obstacles::CompositeSpriteBlock::setPosition(float x, float y) noexcept {
    m_area.setPosition(x, y);
}

void Obstacles::CompositeSpriteBlock::setSize(const Components::Size &size) noexcept {
    m_area.setSize(size);
}

void Obstacles::CompositeSpriteBlock::setRotation(float angle) noexcept {
    m_area.setRotation(angle);
}
