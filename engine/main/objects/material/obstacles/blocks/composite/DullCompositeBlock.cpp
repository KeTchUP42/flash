//
// Created by roman on 11.09.2020.
//

#include "DullCompositeBlock.h"

Obstacles::DullCompositeBlock::DullCompositeBlock(const Components::Area &area, const ObstacleProperties &properties,
                                                  const std::shared_ptr<Components::ISprite> &sprite)
        : CompositeSpriteBlock(area, properties, sprite) {}

void Obstacles::DullCompositeBlock::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Obstacles::DullCompositeBlock::selfMove(Unite::Unifier *unifier) {
    this->move(m_properties.speed.xSpeed, m_properties.speed.ySpeed);
}

void Obstacles::DullCompositeBlock::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}
