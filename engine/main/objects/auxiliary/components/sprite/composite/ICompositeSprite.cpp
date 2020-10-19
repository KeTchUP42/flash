//
// Created by roman on 19.10.2020.
//

#include "ICompositeSprite.h"

void Components::ICompositeSprite::addSprite(Components::ISprite *sprite) noexcept {
    m_sprites.push_back(std::shared_ptr<Components::ISprite>(sprite));
    sprite->setParent(this);
}

void Components::ICompositeSprite::addSprite(const std::shared_ptr<ISprite> &sprite) noexcept {
    m_sprites.push_back(sprite);
    sprite->setParent(this);
}

void Components::ICompositeSprite::removeSprite(Components::ISprite *sprite) noexcept {
    m_sprites.remove_if([sprite](const std::shared_ptr<Components::ISprite> &sprt) -> bool {
        return sprt.get() == sprite;
    });
    sprite->setParent(nullptr);
}

void Components::ICompositeSprite::removeSprite(const std::shared_ptr<ISprite> &sprite) noexcept {
    m_sprites.remove(sprite);
    sprite->setParent(nullptr);
}
