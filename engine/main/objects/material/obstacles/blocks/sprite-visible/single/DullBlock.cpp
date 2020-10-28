//
// Created by roman on 11.09.2020.
//

#include "DullBlock.h"

Obstacles::DullBlock::DullBlock(const ObstacleProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                                const std::shared_ptr<Material::Algorithms> &algorithms)
        : SingleSpriteBlock(properties, sprite, algorithms) {}

void Obstacles::DullBlock::selfAction(Unite::Unifier *unifier) {
    //..
}