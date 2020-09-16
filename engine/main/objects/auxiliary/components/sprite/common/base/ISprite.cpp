//
// Created by roman on 16.09.2020.
//

#include "ISprite.h"

void Components::ISprite::setParent(Components::ISprite *sprite) noexcept {
    _parent = sprite;
}

Components::ISprite *Components::ISprite::getParent() const noexcept {
    return _parent;
}
