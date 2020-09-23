//
// Created by roman on 30.08.2020.
//

#include "SpriteBox.h"
#include "../../../../../../utils/other/Calculations.h"

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
    this->setPosition(OtherUtils::pointToPointRotation(this->getPosition(), angle, point));
    this->rotate(angle);
}

bool Components::SpriteBox::collision(float x, float y) const noexcept {
    return OtherUtils::collision(Point(x, y), *this);
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

void Components::SpriteBox::setSize(const Components::Size &size) noexcept {
    _size = size;
    _sprite->setScale(static_cast<float>(_size.width) / _texture->getSize().x,
                      static_cast<float>(_size.height) / _texture->getSize().y);
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
