//
// Created by roman on 30.08.2020.
//

#include "CompositeSpriteBox.h"

void Components::CompositeSpriteBox::draw(sf::RenderTarget &target) const noexcept {
    for (const std::shared_ptr<ISpriteBox> &spriteBox : _spriteBoxes) {
        spriteBox->draw(target);
    }
}

void Components::CompositeSpriteBox::move(int xlength, int ylength) noexcept {
    for (const std::shared_ptr<ISpriteBox> &spriteBox : _spriteBoxes) {
        spriteBox->move(xlength, ylength);
    }
}

bool Components::CompositeSpriteBox::collision(int x, int y) const noexcept {
    for (const std::shared_ptr<ISpriteBox> &spriteBox : _spriteBoxes) {
        if (spriteBox->collision(x, y)) return true;
    }
    return false;
}

void Components::CompositeSpriteBox::update(const sf::Event &event, sf::RenderWindow &sender) noexcept {
    for (const std::shared_ptr<ISpriteBox> &spriteBox : _spriteBoxes) {
        spriteBox->update(event, sender);
    }
}

void Components::CompositeSpriteBox::addSpriteBox(Components::ISpriteBox *spriteBox) noexcept {
    _spriteBoxes.push_back(std::shared_ptr<Components::ISpriteBox>(spriteBox));
}

void Components::CompositeSpriteBox::addSpriteBox(const std::shared_ptr<ISpriteBox> &spriteBox) noexcept {
    _spriteBoxes.push_back(spriteBox);
}

void Components::CompositeSpriteBox::removeSpriteBox(const std::shared_ptr<ISpriteBox> &spriteBox) noexcept {
    _spriteBoxes.remove(spriteBox);
}
