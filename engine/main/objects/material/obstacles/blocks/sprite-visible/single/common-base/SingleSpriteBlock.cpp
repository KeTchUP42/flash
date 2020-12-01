//
// Created by roman on 11.09.2020.
//

#include "SingleSpriteBlock.h"

Obstacles::SingleSpriteBlock::SingleSpriteBlock(
        const Material::MaterialProperties &material_properties,
        const Obstacles::ObstacleProperties &properties,
        const std::shared_ptr<Components::ISpriteBox> &sprite,
        const std::shared_ptr<Material::Algorithms> &algorithms
) : Obstacles::AnalyzingBlock(material_properties, properties, sprite->getArea(), algorithms), m_sprite(sprite) {}

void Obstacles::SingleSpriteBlock::loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept {
    m_sprite->setTexture(texture);
}

void Obstacles::SingleSpriteBlock::draw(sf::RenderTarget &target) const noexcept {
    m_sprite->draw(target);
}

void Obstacles::SingleSpriteBlock::move(float offsetX, float offsetY) noexcept {
    Obstacles::Block::move(offsetX, offsetY);
    m_sprite->move(offsetX, offsetY);
}

void Obstacles::SingleSpriteBlock::rotate(float angle) noexcept {
    Obstacles::Block::rotate(angle);
    m_sprite->rotate(angle);
}

void Obstacles::SingleSpriteBlock::rotate(float angle, float x, float y) noexcept {
    Obstacles::Block::rotate(angle, x, y);
    m_sprite->rotate(angle, x, y);
}

void Obstacles::SingleSpriteBlock::rotate(float angle, const Components::Point &point) noexcept {
    Obstacles::Block::rotate(angle, point);
    m_sprite->rotate(angle, point);
}

void Obstacles::SingleSpriteBlock::setPosition(const Components::Point &point) noexcept {
    Obstacles::Block::setPosition(point);
    m_sprite->setPosition(point);
}

void Obstacles::SingleSpriteBlock::setPosition(float x, float y) noexcept {
    Obstacles::Block::setPosition(x, y);
    m_sprite->setPosition(x, y);
}

void Obstacles::SingleSpriteBlock::setSize(const Components::Size &size) noexcept {
    Obstacles::Block::setSize(size);
    m_sprite->setSize(size);
}

void Obstacles::SingleSpriteBlock::setRotation(float angle) noexcept {
    Obstacles::Block::setRotation(angle);
    m_sprite->setRotation(angle);
}
