//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_ANALYZINGMOB_H
#define FLASH_ANALYZINGMOB_H

#include "Mob.h"
#include "../../../common/algorithms/Algorithms.h"

namespace Mobs {

    class AnalyzingMob : public Mob {
    public:
        explicit AnalyzingMob(
                const Mobs::MobProperties &properties,
                const Components::Area &area,
                const std::shared_ptr<Components::ISpriteBox> &sprite,
                const std::shared_ptr<::Material::Algorithms> &algorithms
        ) : Mob(properties, area, sprite), m_algorithms(algorithms) {}

        const std::shared_ptr<::Material::Algorithms> &getAlgorithms() const {
            return m_algorithms;
        }

    protected:
        std::shared_ptr<::Material::Algorithms> m_algorithms;
    };
}

#endif //FLASH_ANALYZINGMOB_H
