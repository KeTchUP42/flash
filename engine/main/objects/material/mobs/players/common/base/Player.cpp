//
// Created by roman on 08.09.2020.
//

#include "Player.h"

Mobs::Player::Player(const Mobs::MobProperties &properties, const Components::Area &area, const std::shared_ptr<Components::ISpriteBox> &sprite)
        : Mobs::Mob(properties, area, sprite) {}

void Mobs::Player::loadKeyMap(const std::map<Mobs::KeyAlias, sf::Keyboard::Key> &keyMap) noexcept {
    m_keyMap = keyMap;
}

const std::map<Mobs::KeyAlias, sf::Keyboard::Key> Mobs::Player::getKeyMap() const noexcept {
    return m_keyMap;
}