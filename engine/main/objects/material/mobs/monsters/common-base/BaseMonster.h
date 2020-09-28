//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_BASEMONSTER_H
#define FLASH_BASEMONSTER_H

#include "Monster.h"
#include "../../../common/algorithms/Algorithms.h"

namespace Mobs {

    class BaseMonster : public Monster {
    public:
        explicit BaseMonster(const Mobs::MonsterProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                             const std::shared_ptr<::Material::Algorithms> &algorithms)
                : Monster(properties, sprite), m_algorithms(algorithms) {}

        explicit BaseMonster(const Mobs::MonsterProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                             Material::Algorithms *algorithms)
                : Monster(properties, sprite), m_algorithms(algorithms) {}

    protected:
        std::shared_ptr<::Material::Algorithms> m_algorithms;
    };
}

#endif //FLASH_BASEMONSTER_H
