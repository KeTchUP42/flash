//
// Created by roman on 11.09.2020.
//

#include "CompositeSpriteBlock.h"

Obstacles::CompositeSpriteBlock::CompositeSpriteBlock(
        const ObstacleProperties &properties,
        const Components::Area &area,
        const std::shared_ptr<Components::ISprite> &sprite,
        const std::shared_ptr<Material::Algorithms> &algorithms
) : Obstacles::AnalyzingBlock(properties, area, algorithms), m_sprite(sprite) {}

void Obstacles::CompositeSpriteBlock::loadNewSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    m_sprite.reset(); //Safe delete.
    m_sprite = sprite;
}

void Obstacles::CompositeSpriteBlock::draw(sf::RenderTarget &target) const noexcept {
    m_sprite->draw(target);
}

void Obstacles::CompositeSpriteBlock::move(float offsetX, float offsetY) noexcept {
    Obstacles::Block::move(offsetX, offsetY);
    m_sprite->move(offsetX, offsetY);
}

void Obstacles::CompositeSpriteBlock::rotate(float angle) noexcept {
    Obstacles::Block::rotate(angle);
    m_sprite->rotate(angle);
}

void Obstacles::CompositeSpriteBlock::rotate(float angle, float x, float y) noexcept {
    Obstacles::Block::rotate(angle, x, y);
    m_sprite->rotate(angle, x, y);
}

void Obstacles::CompositeSpriteBlock::rotate(float angle, const Components::Point &point) noexcept {
    Obstacles::Block::rotate(angle, point);
    m_sprite->rotate(angle, point);
}
