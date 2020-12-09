//
// Created by roman on 28.09.2020.
//

#include "Algorithms.h"

Material::Algorithms::Algorithms(const Material::AlgorithmsParams &params)
        : m_collision(std::make_shared<Material::Collision>(params.analysisStepX, params.analysisStepY)) {}

Material::Algorithms::Algorithms(const std::shared_ptr<Material::Collision> &collision) : m_collision(collision) {}

const Material::Collision &Material::Algorithms::getCollision() const {
    return *m_collision;
}
