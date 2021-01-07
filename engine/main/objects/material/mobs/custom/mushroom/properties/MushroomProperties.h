//
// Created by roman on 10.10.2020.
//

#ifndef FLASH_MUSHROOMPROPERTIES_H
#define FLASH_MUSHROOMPROPERTIES_H

#include "../../../../common/properties/ParamsTypes.h"

namespace Mobs {

    /**
     * @brief Struct contains mushroom numeric properties.
     */
    struct MushroomProperties {
        MushroomProperties(
                Material::FRAC_PARAM punchPower,
                Material::FRAC_PARAM elasticityLevel
        ) : punchPower(punchPower),
            elasticityLevel(elasticityLevel) {}

        /**
         * @brief Mushroom's push power.
         */
        Material::FRAC_PARAM punchPower;

        /**
         * @brief The percentage of vertical speed that the player will return to when he jumps a mushroom.
         */
        Material::FRAC_PARAM elasticityLevel;
    };
}

#endif //FLASH_MUSHROOMPROPERTIES_H
