//
// Created by roman on 11.09.2020.
//

#include "DullBlock.h"

Obstacles::DullBlock::DullBlock(const ObstacleProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                                const std::shared_ptr<Material::Collision> &collision)
        : SingleSpriteBlock(properties, sprite, collision) {}

void Obstacles::DullBlock::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Obstacles::DullBlock::selfMove(Unite::Unifier *unifier) {
    this->move(_properties.speed.xSpeed, _properties.speed.ySpeed);
}

void Obstacles::DullBlock::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}
