//
// Created by roman on 11.09.2020.
//

#include "DullBlock.h"

Obstacles::DullBlock::DullBlock(
        const Material::MaterialProperties &material_properties,
        const ObstacleProperties &properties,
        const std::shared_ptr<Components::ISpriteBox> &sprite,
        const std::shared_ptr<Material::Algorithms> &algorithms
) : SingleSpriteBlock(material_properties, properties, sprite, algorithms) {}

void Obstacles::DullBlock::selfAction(Unite::Unifier *unifier) {
    //..
}