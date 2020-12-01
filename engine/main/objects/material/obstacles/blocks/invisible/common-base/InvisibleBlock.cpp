//
// Created by roman on 06.10.2020.
//

#include "InvisibleBlock.h"

Obstacles::InvisibleBlock::InvisibleBlock(
        const Material::MaterialProperties &material_properties,
        const Obstacles::ObstacleProperties &properties,
        const Components::Area &area,
        const std::shared_ptr<Material::Algorithms> &algorithms
) : Obstacles::AnalyzingBlock(material_properties, properties, area, algorithms) {}

void Obstacles::InvisibleBlock::draw(sf::RenderTarget &target) const noexcept {
    //..
}