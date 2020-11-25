//
// Created by roman on 25.11.2020.
//

#ifndef FLASH_MOBSCOLLISIONREDUCTION_H
#define FLASH_MOBSCOLLISIONREDUCTION_H

#include "../base/Mob.h"
#include "../../../common/algorithms/Algorithms.h"

namespace Mobs {
    namespace RD {

        /**
         * @brief The function contains the basic implementation of the collision analysis with blocks from the unifier.
         * @param mob Target object that is being processed.
         * @param algorithms Configured facade of necessary algorithms.
         * @param unifier Scene unifier.
         */
        void ordinateBlocksNaturalCollision(Mobs::Mob *mob, Material::Algorithms &algorithms, Unite::Unifier *unifier) noexcept;

        /**
         * @brief The function contains the basic implementation of the collision analysis with blocks from the unifier.
         * @param mob Target object that is being processed.
         * @param algorithms Configured facade of necessary algorithms.
         * @param unifier Scene unifier.
         */
        void abscissaBlocksNaturalCollision(Mobs::Mob *mob, Material::Algorithms &algorithms, Unite::Unifier *unifier) noexcept;
    }
}
#endif //FLASH_MOBSCOLLISIONREDUCTION_H
