//
// Created by roman on 29.11.2020.
//

#ifndef FLASH_BULLETPROPERTIES_H
#define FLASH_BULLETPROPERTIES_H

#include "../../../../common/properties/ParamsTypes.h"

namespace Particles {

    /**
     * @brief Struct contains all bullet numeric properties.
     */
    struct BulletProperties {
        explicit BulletProperties(
                Material::FRAC_PARAM damage
        ) : damage(damage) {}

        /**
         * @brief Bullet's damage.
         */
        Material::FRAC_PARAM damage;
    };
}

#endif //FLASH_BULLETPROPERTIES_H
