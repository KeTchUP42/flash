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
    float newX = point.x + (point.y - _point.y) * std::sin(angleInRadians) + (_point.x - point.x) * std::cos(angleInRadians);
    float newY = point.y + (_point.y - point.y) * std::cos(angleInRadians) + (_point.x - point.x) * std::sin(angleInRadians);
    this->setPosition(Point(newX, newY));
    this->rotate(angle);
}

/**
 * @brief This is help function for Components::SpriteBox::collision method.
 * @param Px Searching X.
 * @param Py Searching Y.
 * @param Ax First vector X.
 * @param Ay First vector Y.
 * @param Bx Second vector X.
 * @param By Second vector Y.
 * @return The value responsible for the position of the point relative to the vector.
 */
int product(int Px, int Py, int Ax, int Ay, int Bx, int By) {
    return (Bx - Ax) * (Py - Ay) - (By - Ay) * (Px - Ax);
}

bool Components::SpriteBox::collision(int x, int y) const noexcept {
    //If it will not work correct, change coordinates type.
    float angle = _sprite->getRotation() * M_PI / 180;
    int xp2 = -std::sin(angle) + std::cos(angle) * _size.width + _point.x;
    int yp2 = std::cos(angle) + std::sin(angle) * _size.width + _point.y;

    int xp3 = -std::sin(angle) * _size.height + std::cos(angle) * _size.width + _point.x;
    int yp3 = std::cos(angle) * _size.height + std::sin(angle) * _size.width + _point.y;

    int xp4 = -std::sin(angle) * _size.height + std::cos(angle) + _point.x;
    int yp4 = std::cos(angle) * _size.height + std::sin(angle) + _point.y;

    int p1 = product(x, y, _point.x, _point.y, xp2, yp2);
    int p2 = product(x, y, xp2, yp2, xp3, yp3);
    int p3 = product(x, y, xp3, yp3, xp4, yp4);
    int p4 = product(x, y, xp4, yp4, _point.x, _point.y);

    return ((p1 >= 0) && (p2 >= 0) && (p3 >= 0) && (p4 >= 0));
}

void Components::SpriteBox::update(const sf::Event &event, sf::RenderWindow &sender) noexcept {
    //..
}

void Components::SpriteBox::setPosition(const Components::Point &point) noexcept {
    _point = point;
    _sprite->setPosition(_point.x, _point.y);
}

void Components::SpriteBox::setRotation(float angle) noexcept {
    _sprite->setRotation(angle);
}

const Components::Point &Components::SpriteBox::getPoint() const noexcept {
    return _point;
}

const Components::Size &Components::SpriteBox::getSize() const noexcept {
    return _size;
}

