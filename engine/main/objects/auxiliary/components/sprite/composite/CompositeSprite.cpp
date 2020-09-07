//
// Created by roman on 30.08.2020.
//

#include "CompositeSprite.h"

void Components::CompositeSprite::draw(sf::RenderTarget &target) const noexcept {
    for (const std::shared_ptr<ISprite> &sprite : _sprites) {
        sprite->draw(target);
    }
}

void Components::CompositeSprite::move(int xlength, int ylength) noexcept {
    for (const std::shared_ptr<ISprite> &sprite : _sprites) {
        sprite->move(xlength, ylength);
    }
}

void Components::CompositeSprite::rotate(float angle) {
    for (const std::shared_ptr<ISprite> &sprite : _sprites) {
        sprite->rotate(angle); //todo: fix uncorrect code.
    }
}

bool Components::CompositeSprite::collision(int x, int y) const noexcept {
    for (const std::shared_ptr<ISprite> &sprite : _sprites) {
        if (sprite->collision(x, y)) return true;
    }
    return false;
}

void Components::CompositeSprite::update(const sf::Event &event, sf::RenderWindow &sender) noexcept {
    for (const std::shared_ptr<ISprite> &sprite : _sprites) {
        sprite->update(event, sender);
    }
}

void Components::CompositeSprite::addSprite(Components::ISprite *sprite) noexcept {
    _sprites.push_back(std::shared_ptr<Components::ISprite>(sprite));
}

void Components::CompositeSprite::addSprite(const std::shared_ptr<ISprite> &sprite) noexcept {
    _sprites.push_back(sprite);
}

void Components::CompositeSprite::removeSprite(const std::shared_ptr<ISprite> &sprite) noexcept {
    _sprites.remove(sprite);
}
