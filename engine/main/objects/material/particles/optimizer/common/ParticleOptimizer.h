//
// Created by roman on 30.11.2020.
//

#ifndef FLASH_PARTICLEOPTIMIZER_H
#define FLASH_PARTICLEOPTIMIZER_H

namespace Unite {
    class Unifier;
}

namespace Particles {

    /**
     * @brief The base class of the ParticleOptimizer class hierarchy.
     * @namespace Particles
     *
     * Particle-optimizers used to optimize particles "life" time.
    */
    template<class Type>
    class ParticleOptimizer {
    public:
        ParticleOptimizer() = default;

        /**
         * @brief The method checks the particle state and make optimization whether it needs.
         * @param particle Checking particle.
         * @param unifier Scene unifier.
         * @return Need optimization or optimizated.
         */
        virtual bool optimize(Type *particle, Unite::Unifier &unifier) = 0;

        virtual ~ParticleOptimizer() = default;
    };
}

#include "../../../../unifier/common/Unifier.h"

#endif //FLASH_PARTICLEOPTIMIZER_H
