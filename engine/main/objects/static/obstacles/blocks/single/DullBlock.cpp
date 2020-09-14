//
// Created by roman on 11.09.2020.
//

#include "DullBlock.h"

Obstacles::DullBlock::DullBlock(const std::shared_ptr<Components::ISpriteBox> &sprite) : SingleSpriteBlock(sprite) {}

void Obstacles::DullBlock::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Obstacles::DullBlock::selfMove(Unite::Unifier *unifier) {
    this->move(_speed.xSpeed, _speed.ySpeed);
}

void Obstacles::DullBlock::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}
