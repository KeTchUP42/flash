//
// Created by roman on 06.10.2020.
//

#include "DullInvisibleBlock.h"

Obstacles::DullInvisibleBlock::DullInvisibleBlock(const Obstacles::ObstacleProperties &properties, const Components::Area &area,
                                                  const std::shared_ptr<Material::Algorithms> &algorithms)
        : InvisibleBlock(properties, area, algorithms) {}

void Obstacles::DullInvisibleBlock::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Obstacles::DullInvisibleBlock::selfMove(Unite::Unifier *unifier) {
    this->move(m_properties.speed.xSpeed, m_properties.speed.ySpeed);
}

void Obstacles::DullInvisibleBlock::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}

