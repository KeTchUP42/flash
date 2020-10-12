//
// Created by roman on 29.09.2020.
//

#include "DullBlockGenerator.h"
#include "../../../../material/obstacles/blocks/sprite-visible/single/DullBlock.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "reducing/properties.h"
#include "../reducing/area.h"

Generate::DullBlockGenerator::DullBlockGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::DullBlockGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //algorithms
    std::pair<float, float> collisionParams = std::make_pair<float, float>(std::stof(data.at("COLLISION_ANALYSIS_STEP")),
                                                                           std::stof(data.at("COLLISION_ANALYSIS_STEP")));

    std::shared_ptr<Material::Algorithms> algorithms(
            new Material::Algorithms(m_source.getAlgpool()->loadCollision(collisionParams)));

    unifier.addObstacle(new Obstacles::DullBlock(obstacle(data),
                                                 std::make_shared<Components::SpriteBox>(
                                                         physicalArea(data), m_source.getTexture(data.at("TEXTURE"))), algorithms));
}
