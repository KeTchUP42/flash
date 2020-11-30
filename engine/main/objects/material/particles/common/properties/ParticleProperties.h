//
// Created by roman on 29.11.2020.
//

#ifndef FLASH_PARTICLEPROPERTIES_H
#define FLASH_PARTICLEPROPERTIES_H

#include "../../../common/properties/MaterialObjectProperties.h"

namespace Particles {

    /**
     * @brief Struct contains all particle numeric properties.
     */
    struct ParticleProperties : public Material::MaterialObjectProperties {
        explicit ParticleProperties(const Components::Speed &speed, bool isUnderEffect)
                : MaterialObjectProperties(speed), isUnderEffects(isUnderEffect) {}

        /**
         * @brief If this flag is not set, the particle will be affected by static effects.
         */
        bool isUnderEffects;
    };
}

#endif //FLASH_PARTICLEPROPERTIES_H
