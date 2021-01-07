//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_MOBPROPERTIES_H
#define FLASH_MOBPROPERTIES_H

#include "../../../common/properties/ParamsTypes.h"

namespace Mobs {

    /**
     * @brief Struct contains all mob numeric properties.
     */
    struct MobProperties {
        MobProperties(
                Material::FRAC_PARAM maxHealthPoints,
                Material::FRAC_PARAM healthPoints
        ) : maxHealthPoints(maxHealthPoints),
            healthPoints(healthPoints) {}

        /**
         * @brief The parameter of maximum health points.
         */
        Material::FRAC_PARAM maxHealthPoints;

        /**
         * @brief The parameter sets health points which are necessary for the process of life activities.
         */
        Material::FRAC_PARAM healthPoints;
    };
}

#endif //FLASH_MOBPROPERTIES_H
