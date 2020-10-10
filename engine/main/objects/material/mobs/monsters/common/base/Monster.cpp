//
// Created by roman on 17.09.2020.
//

#include "Monster.h"

Mobs::Monster::Monster(const Mobs::MonsterProperties &properties, const Components::Area &area,
                       const std::shared_ptr<Components::ISpriteBox> &sprite)
        : m_properties(properties), m_area(area), m_sprite(sprite) {}

void Mobs::Monster::loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    m_sprite->setTexture(texture);
}

void Mobs::Monster::draw(sf::RenderTarget &target) const noexcept {
    m_sprite->draw(target);
}

void Mobs::Monster::move(float offsetX, float offsetY) noexcept {
    m_area.move(offsetX, offsetY);
    m_sprite->move(offsetX, offsetY);
}

void Mobs::Monster::rotate(float angle) noexcept {
    m_area.rotate(angle);
    m_sprite->rotate(angle);
}

void Mobs::Monster::rotate(float angle, float x, float y) noexcept {
    Components::Point point(x, y);
    m_area.rotate(angle, point);
    m_sprite->rotate(angle, point);
}

void Mobs::Monster::rotate(float angle, const Components::Point &point) noexcept {
    m_area.rotate(angle, point);
    m_sprite->rotate(angle, point);
}

void Mobs::Monster::addSpeed(float offsetX, float offsetY) noexcept {
    m_properties.speed.xSpeed += offsetX;
    m_properties.speed.ySpeed += offsetY;
}

void Mobs::Monster::setSpeed(const Components::Speed &speed) noexcept {
    m_properties.speed = speed;
}

const Components::Speed &Mobs::Monster::getSpeed() const noexcept {
    return m_properties.speed;
}

const Mobs::MonsterProperties &Mobs::Monster::getProperties() const noexcept {
    return m_properties;
}

const Components::Point &Mobs::Monster::getPosition() const noexcept {
    return m_area.m_point;
}

const Components::Size &Mobs::Monster::getSize() const noexcept {
    return m_area.m_size;
}

float Mobs::Monster::getRotation() const noexcept {
    return m_area.m_angle;
}

void Mobs::Monster::setPosition(const Components::Point &point) noexcept {
    this->setPosition(point.x, point.y);
}

void Mobs::Monster::setPosition(float x, float y) noexcept {
    float spriteOffsetX = m_sprite->getPosition().x - m_area.m_point.x;
    float spriteOffsetY = m_sprite->getPosition().y - m_area.m_point.y;
    m_area.setPosition(x, y);
    m_sprite->setPosition(m_area.m_point.x + spriteOffsetX, m_area.m_point.y + spriteOffsetY);
}

void Mobs::Monster::setSize(const Components::Size &size) noexcept {
    float widthCoeff = static_cast<float>(m_sprite->getSize().width) / m_area.m_size.width;
    float heightCoeff = static_cast<float>(m_sprite->getSize().height) / m_area.m_size.height;
    m_area.setSize(size);
    m_sprite->setSize(Components::Size(m_area.m_size.width * widthCoeff, m_area.m_size.height * heightCoeff));
}

void Mobs::Monster::setRotation(float angle) noexcept {
    m_area.setRotation(angle);
    m_sprite->setRotation(angle);
}

const std::shared_ptr<Components::ISpriteBox> &Mobs::Monster::getSprite() const noexcept {
    return m_sprite;
}
