//
// Created by roman on 30.08.2020.
//

#include "SpriteBox.h"
#include "../../../../../../utils/math/Rectangle.h"

Components::SpriteBox::SpriteBox(const Components::Point &point, const Components::Size &size,
                                 const std::shared_ptr<sf::Texture> &texture)
        : m_point(point), m_size(size), m_texture(texture) {

    m_sprite = std::shared_ptr<sf::Sprite>(new sf::Sprite());
    m_sprite->setTexture(*texture.get(), true);
    m_sprite->setPosition(m_point.x, m_point.y);
    m_sprite->setScale(static_cast<float>(m_size.width) / m_texture->getSize().x,
                       static_cast<float>(m_size.height) / m_texture->getSize().y);
}

void Components::SpriteBox::draw(sf::RenderTarget &target) const noexcept {
    target.draw(*m_sprite.get(), sf::RenderStates::Default);
}

void Components::SpriteBox::move(float offsetX, float offsetY) noexcept {
    m_point.x += offsetX;
    m_point.y += offsetY;
    m_sprite->setPosition(m_point.x, m_point.y);
}

void Components::SpriteBox::rotate(float angle) noexcept {
    m_sprite->rotate(angle);
}

void Components::SpriteBox::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Point(x, y));
}

void Components::SpriteBox::rotate(float angle, const Components::Point &point) noexcept {
    this->setPosition(MathUtils::pointToPointRotation(this->getPosition(), angle, point));
    this->rotate(angle);
}

bool Components::SpriteBox::collision(float x, float y) const noexcept {
    return MathUtils::collision(Point(x, y), *this);
}

void Components::SpriteBox::setPosition(const Components::Point &point) noexcept {
    this->setPosition(point.x, point.y);
}

void Components::SpriteBox::setPosition(float x, float y) noexcept {
    m_point = Point(x, y);
    m_sprite->setPosition(m_point.x, m_point.y);
}

void Components::SpriteBox::setSize(const Components::Size &size) noexcept {
    m_size = size;
    m_sprite->setScale(static_cast<float>(m_size.width) / m_texture->getSize().x,
                       static_cast<float>(m_size.height) / m_texture->getSize().y);
}

void Components::SpriteBox::setRotation(float angle) noexcept {
    m_sprite->setRotation(angle);
}

float Components::SpriteBox::getRotation() const noexcept {
    return m_sprite->getRotation();
}

const std::shared_ptr<sf::Sprite> &Components::SpriteBox::getSprite() const noexcept {
    return m_sprite;
}

const sf::Texture *Components::SpriteBox::getTexture() const noexcept {
    return m_sprite->getTexture();
}

void Components::SpriteBox::setTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    m_texture.reset(); // Safe delete.
    m_texture = texture;
    m_sprite->setTexture(*m_texture.get(), true);
}

const sf::IntRect &Components::SpriteBox::getTextureRect() const noexcept {
    return m_sprite->getTextureRect();
}

sf::Color Components::SpriteBox::getColor() const noexcept {
    return m_sprite->getColor();
}

void Components::SpriteBox::setColor(const sf::Color &color) noexcept {
    m_sprite->setColor(color);
}

const Components::Point &Components::SpriteBox::getPosition() const noexcept {
    return m_point;
}

const Components::Size &Components::SpriteBox::getSize() const noexcept {
    return m_size;
}
