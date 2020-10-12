//
// Created by roman on 06.10.2020.
//

#include "DullInvisibleBlockGenarator.h"
#include "../../../../material/common/algorithms/Algorithms.h"
#include "../../../../material/obstacles/blocks/invisible/DullInvisibleBlock.h"
#include "reducing/properties.h"
#include "../reducing/area.h"

Generate::DullInvisibleBlockGenarator::DullInvisibleBlockGenarator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::DullInvisibleBlockGenarator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //algorithms
    std::pair<float, float> collisionParams = std::make_pair<float, float>(std::stof(data.at("COLLISION_ANALYSIS_STEP")),
                                                                           std::stof(data.at("COLLISION_ANALYSIS_STEP")));

    std::shared_ptr<Material::Algorithms> algorithms(
            new Material::Algorithms(m_source.getAlgpool()->loadCollision(collisionParams)));

    unifier.addObstacle(
            new Obstacles::DullInvisibleBlock(
                    obstacle(data), physicalArea(data), algorithms));
}
