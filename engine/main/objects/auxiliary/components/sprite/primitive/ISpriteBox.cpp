//
// Created by roman on 12.10.2020.
//

#include <memory>
#include "ISpriteBox.h"

Components::ISpriteBox::ISpriteBox(const std::shared_ptr<sf::Texture> &texture, const std::shared_ptr<sf::Sprite> &sprite)
        : m_texture(texture), m_sprite(sprite) {}

Components::ISpriteBox::ISpriteBox(const std::shared_ptr<sf::Texture> &texture, sf::Sprite *sprite)
        : m_texture(texture), m_sprite(sprite) {}

const std::shared_ptr<sf::Sprite> &Components::ISpriteBox::getSprite() const noexcept {
    return m_sprite;
}

const std::shared_ptr<sf::Texture> &Components::ISpriteBox::getTexture() const noexcept {
    return m_texture;
}

void Components::ISpriteBox::setTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    m_texture.reset(); // Safe delete.
    m_texture = texture;
    m_sprite->setTexture(*m_texture.get(), true);
}

const sf::IntRect &Components::ISpriteBox::getTextureRect() const noexcept {
    return m_sprite->getTextureRect();
}

sf::Color Components::ISpriteBox::getColor() const noexcept {
    return m_sprite->getColor();
}

void Components::ISpriteBox::setColor(const sf::Color &color) noexcept {
    m_sprite->setColor(color);
}

