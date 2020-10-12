//
// Created by roman on 06.10.2020.
//

#include "PlatformBlockGenerator.h"
#include "../../../../material/common/algorithms/Algorithms.h"
#include "../../../../material/obstacles/blocks/sprite-visible/single/PlatformBlock.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "reduction/Properties.h"
#include "../reduction/area.h"

Generate::PlatformBlockGenerator::PlatformBlockGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::PlatformBlockGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //algorithms
    std::pair<float, float> collisionParams = std::make_pair<float, float>(std::stof(data.at("COLLISION_ANALYSIS_STEP")),
                                                                           std::stof(data.at("COLLISION_ANALYSIS_STEP")));

    std::shared_ptr<Material::Algorithms> algorithms(
            new Material::Algorithms(m_source.getAlgpool()->loadCollision(collisionParams)));

    unifier.addObstacle(new Obstacles::PlatformBlock(obstacle(data),
                                                     std::make_shared<Components::SpriteBox>(
                                                             physicalArea(data), m_source.getTexture(data.at("TEXTURE"))), algorithms));
}
