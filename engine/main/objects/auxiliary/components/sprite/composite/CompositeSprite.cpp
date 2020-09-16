//
// Created by roman on 30.08.2020.
//

#include "CompositeSprite.h"

void Components::CompositeSprite::draw(sf::RenderTarget &target) const noexcept {
    for (const std::shared_ptr<ISprite> &sprite : _sprites) {
        sprite->draw(target);
    }
}

void Components::CompositeSprite::move(float offsetX, float offsetY) noexcept {
    for (const std::shared_ptr<ISprite> &sprite : _sprites) {
        sprite->move(offsetX, offsetY);
    }
}

void Components::CompositeSprite::rotate(float angle) noexcept {
    for (const std::shared_ptr<ISprite> &sprite : _sprites) {
        sprite->rotate(angle);
    }
}

void Components::CompositeSprite::rotate(float angle, float x, float y) noexcept {
    this->rotate(angle, Point(x, y));
}

void Components::CompositeSprite::rotate(float angle, const Components::Point &point) noexcept {
    for (const std::shared_ptr<ISprite> &sprite : _sprites) {
        sprite->rotate(angle, point);
    }
}

bool Components::CompositeSprite::collision(float x, float y) const noexcept {
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
    sprite->setParent(this);
}

void Components::CompositeSprite::addSprite(const std::shared_ptr<ISprite> &sprite) noexcept {
    _sprites.push_back(sprite);
    sprite->setParent(this);
}

void Components::CompositeSprite::removeSprite(Components::ISprite *sprite) noexcept {
    _sprites.remove_if([sprite](const std::shared_ptr<Components::ISprite> &sprt) -> bool {
        return sprt.get() == sprite;
    });
    sprite->setParent(nullptr);
}

void Components::CompositeSprite::removeSprite(const std::shared_ptr<ISprite> &sprite) noexcept {
    _sprites.remove(sprite);
    sprite->setParent(nullptr);
}
