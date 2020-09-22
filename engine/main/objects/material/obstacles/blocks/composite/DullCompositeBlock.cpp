//
// Created by roman on 11.09.2020.
//

#include "DullCompositeBlock.h"

Obstacles::DullCompositeBlock::DullCompositeBlock(const Components::Point &point, const Components::Size &size,
                                                  const ObstacleProperties &properties,
                                                  const std::shared_ptr<Components::ISprite> &sprite)
        : CompositeSpriteBlock(point, size, properties, sprite) {}

void Obstacles::DullCompositeBlock::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Obstacles::DullCompositeBlock::selfMove(Unite::Unifier *unifier) {
    this->move(_speed.xSpeed, _speed.ySpeed);
}

void Obstacles::DullCompositeBlock::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}
