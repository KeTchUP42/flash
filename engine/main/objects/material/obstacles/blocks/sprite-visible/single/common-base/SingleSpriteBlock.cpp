//
// Created by roman on 11.09.2020.
//

#include "SingleSpriteBlock.h"

Obstacles::SingleSpriteBlock::SingleSpriteBlock(const Obstacles::ObstacleProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                                                const std::shared_ptr<Material::Algorithms> &algorithms)
        : Obstacles::Obstacle(properties), m_sprite(sprite), m_algorithms(algorithms) {}

void Obstacles::SingleSpriteBlock::loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    m_sprite->setTexture(texture);
}

void Obstacles::SingleSpriteBlock::draw(sf::RenderTarget &target) const noexcept {
    m_sprite->draw(target);
}

void Obstacles::SingleSpriteBlock::move(float offsetX, float offsetY) noexcept {
    m_sprite->move(offsetX, offsetY);
}

void Obstacles::SingleSpriteBlock::rotate(float angle) noexcept {
    m_sprite->rotate(angle);
}

void Obstacles::SingleSpriteBlock::rotate(float angle, float x, float y) noexcept {
    m_sprite->rotate(angle, x, y);
}

void Obstacles::SingleSpriteBlock::rotate(float angle, const Components::Point &point) noexcept {
    m_sprite->rotate(angle, point);
}

void Obstacles::SingleSpriteBlock::addSpeed(float offsetX, float offsetY) noexcept {
    m_properties.speed.xSpeed += offsetX;
    m_properties.speed.ySpeed += offsetY;
}

void Obstacles::SingleSpriteBlock::setSpeed(const Components::Speed &speed) noexcept {
    m_properties.speed = speed;
}

const Components::Speed &Obstacles::SingleSpriteBlock::getSpeed() const noexcept {
    return m_properties.speed;
}

const Components::Point &Obstacles::SingleSpriteBlock::getPosition() const noexcept {
    return m_sprite->getPosition();
}

const Components::Size &Obstacles::SingleSpriteBlock::getSize() const noexcept {
    return m_sprite->getSize();
}

float Obstacles::SingleSpriteBlock::getRotation() const noexcept {
    return m_sprite->getRotation();
}

const Obstacles::ObstacleProperties &Obstacles::SingleSpriteBlock::getProperties() const noexcept {
    return m_properties;
}

void Obstacles::SingleSpriteBlock::setPosition(const Components::Point &point) noexcept {
    m_sprite->setPosition(point);
}

void Obstacles::SingleSpriteBlock::setPosition(float x, float y) noexcept {
    m_sprite->setPosition(Components::Point(x, y));
}

void Obstacles::SingleSpriteBlock::setSize(const Components::Size &size) noexcept {
    m_sprite->setSize(size);
}

void Obstacles::SingleSpriteBlock::setRotation(float angle) noexcept {
    m_sprite->setRotation(angle);
}
