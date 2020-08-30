//
// Created by roman on 30.08.2020.
//

#include "SpriteBox.h"

Components::SpriteBox::SpriteBox(Components::Point point, Components::Size size, std::shared_ptr<sf::Texture> texture)
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

void Components::SpriteBox::move(int x, int y) noexcept {
    _point.x += x;
    _point.y += y;
    _sprite->setPosition(_point.x, _point.y);
}

bool Components::SpriteBox::collision(int x, int y) const noexcept {
    return ((x >= _point.x) && (x <= _point.x + _size.width)) && ((y >= _point.y) && (y <= _point.y + _size.height));
}

void Components::SpriteBox::update(const sf::Event &event, sf::RenderWindow &sender) noexcept {
    //..
}

