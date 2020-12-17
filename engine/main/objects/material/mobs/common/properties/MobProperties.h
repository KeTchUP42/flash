//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_MOBPROPERTIES_H
#define FLASH_MOBPROPERTIES_H

#include "../../../common/properties/MaterialProperties.h"

namespace Mobs {

    /**
     * @brief Struct contains all mob numeric properties.
     */
    struct MobProperties {
        explicit MobProperties(float maxHealthPoints, float healthPoints)
                : maxHealthPoints(maxHealthPoints), healthPoints(healthPoints) {}

        /**
         * @brief The parameter of maximum health points.
         */
        float maxHealthPoints;

        /**
         * @brief The parameter sets health points which are necessary for the process of life activities.
         */
        float healthPoints;
    };
}

#endif //FLASH_MOBPROPERTIES_H
