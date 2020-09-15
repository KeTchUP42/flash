//
// Created by roman on 30.08.2020.
//

#include "SpriteBox.h"

#define _USE_MATH_DEFINES

#include <math.h>

Components::SpriteBox::SpriteBox(const Components::Point &point, const Components::Size &size,
                                 const std::shared_ptr<sf::Texture> &texture)
        : _point(point), _size(size), _texture(texture) {

    _sprite = std::shared_ptr<sf::Sprite>(new sf::Sprite());
    _sprite->setTexture(*texture.get(), true);
    _sprite->setPosition(_point.x, _point.y);
    _sprite->setScale(static_cast<float>(_size.width) / _texture->getSize().x,
                      static_cast<float>(_size.height) / _texture->getSize().y);
}

void Components::SpriteBox::draw(sf::RenderTarget &target) const noexcept {
    target.draw(*_sprite.get(), sf::RenderStates::Default);
}

void Components::SpriteBox::move(float offsetX, float offsetY) noexcept {
    _point.x += offsetX;
    _point.y += offsetY;
    _sprite->setPosition(_point.x, _point.y);
}

void Components::SpriteBox::rotate(float angle) noexcept {
    _sprite->rotate(angle);
}

void Components::SpriteBox::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Point(x, y));
}

void Components::SpriteBox::rotate(float angle, const Components::Point &point) noexcept {
    float angleInRadians = angle * M_PI / 180;
    this->setPosition(
            point.x + (point.y - _point.y) * std::sin(angleInRadians) + (_point.x - point.x) * std::cos(angleInRadians),
            point.y + (_point.y - point.y) * std::cos(angleInRadians) + (_point.x - point.x) * std::sin(angleInRadians)
    );
    this->rotate(angle);
}

/**
 * @brief This is help function for Components::SpriteBox::collision method.
 * @return The value responsible for the position of the point relative to the vector.
 */
static inline int product(float Px, float Py, float Ax, float Ay, float Bx, float By) {
    return (Bx - Ax) * (Py - Ay) - (By - Ay) * (Px - Ax);
}

bool Components::SpriteBox::collision(float x, float y) const noexcept {
    float angle = _sprite->getRotation() * M_PI / 180;
    float xp2 = -std::sin(angle) + std::cos(angle) * _size.width + _point.x;
    float yp2 = std::cos(angle) + std::sin(angle) * _size.width + _point.y;

    float xp3 = -std::sin(angle) * _size.height + std::cos(angle) * _size.width + _point.x;
    float yp3 = std::cos(angle) * _size.height + std::sin(angle) * _size.width + _point.y;

    float xp4 = -std::sin(angle) * _size.height + std::cos(angle) + _point.x;
    float yp4 = std::cos(angle) * _size.height + std::sin(angle) + _point.y;

    return ((product(x, y, _point.x, _point.y, xp2, yp2) >= 0) &&
            (product(x, y, xp2, yp2, xp3, yp3) >= 0) &&
            (product(x, y, xp3, yp3, xp4, yp4) >= 0) &&
            (product(x, y, xp4, yp4, _point.x, _point.y) >= 0));
}

void Components::SpriteBox::update(const sf::Event &event, sf::RenderWindow &sender) noexcept {
    //..
}

void Components::SpriteBox::setPosition(const Components::Point &point) noexcept {
    this->setPosition(point.x, point.y);
}

void Components::SpriteBox::setPosition(float x, float y) noexcept {
    _point = Point(x, y);
    _sprite->setPosition(_point.x, _point.y);
}

void Components::SpriteBox::setRotation(float angle) noexcept {
    _sprite->setRotation(angle);
}

float Components::SpriteBox::getRotation() const noexcept {
    return _sprite->getRotation();
}

const std::shared_ptr<sf::Sprite> &Components::SpriteBox::getSprite() const noexcept {
    return _sprite;
}

const sf::Texture *const Components::SpriteBox::getTexture() const noexcept {
    return _sprite->getTexture();
}

void Components::SpriteBox::setTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    _texture.reset(); // Safe delete.
    _texture = texture;
    _sprite->setTexture(*_texture.get(), true);
}

const sf::IntRect &Components::SpriteBox::getTextureRect() const noexcept {
    return _sprite->getTextureRect();
}

sf::Color Components::SpriteBox::getColor() const noexcept {
    return _sprite->getColor();
}

void Components::SpriteBox::setColor(const sf::Color &color) noexcept {
    _sprite->setColor(color);
}

const Components::Point &Components::SpriteBox::getPosition() const noexcept {
    return _point;
}

const Components::Size &Components::SpriteBox::getSize() const noexcept {
    return _size;
}
