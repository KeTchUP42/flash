//
// Created by roman on 29.09.2020.
//

#include "AlgorithmsPool.h"


std::shared_ptr<Material::Collision>
Creation::Pools::AlgorithmsPool::loadCollision(const std::pair<float, float> &params) noexcept {
    if (m_collision[params].get() == nullptr) {
        m_collision[params] = std::make_shared<Material::Collision>(params.first, params.second);
    }

    return m_collision[params];
}
