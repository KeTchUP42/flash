//
// Created by roman on 29.11.2020.
//

#ifndef FLASH_PARTICLEPROPERTIES_H
#define FLASH_PARTICLEPROPERTIES_H

#include "../../../common/properties/ParamsTypes.h"

namespace Particles {

    /**
     * @brief Struct contains all particle numeric properties.
     */
    struct ParticleProperties {
        explicit ParticleProperties(
                Material::BOOL_PARAM isUnderEffect
        ) : isUnderEffects(isUnderEffect) {}

        /**
         * @brief If this flag is not set, the particle will be affected by static effects.
         */
        Material::BOOL_PARAM isUnderEffects;
    };
}

#endif //FLASH_PARTICLEPROPERTIES_H
