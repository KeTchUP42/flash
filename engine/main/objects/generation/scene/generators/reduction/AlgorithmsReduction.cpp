//
// Created by roman on 13.10.2020.
//

#include "AlgorithmsReduction.h"

std::shared_ptr<Material::Algorithms>
Generate::loadAlgorithms(const IniUtil::Analyzer::IniBlock &data, Generate::Pools::SourcePool &pool) noexcept {
    //collision
    std::pair<float, float> collisionParams = std::make_pair<float, float>(std::stof(data.at("COLLISION_ANALYSIS_STEP")),
                                                                           std::stof(data.at("COLLISION_ANALYSIS_STEP")));
    return std::shared_ptr<Material::Algorithms>(
            new Material::Algorithms(pool.getAlgpool()->loadCollision(collisionParams)));
}
