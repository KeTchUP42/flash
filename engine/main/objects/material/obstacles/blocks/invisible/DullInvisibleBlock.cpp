//
// Created by roman on 06.10.2020.
//

#include "DullInvisibleBlock.h"

Obstacles::DullInvisibleBlock::DullInvisibleBlock(
        const Material::MaterialProperties &material_properties,
        const Obstacles::ObstacleProperties &properties,
        const Components::Area &area,
        const std::shared_ptr<Material::Algorithms> &algorithms
) : InvisibleBlock(material_properties, properties, area, algorithms) {}

void Obstacles::DullInvisibleBlock::selfAction(Unite::Unifier *unifier) {
    //..
}
