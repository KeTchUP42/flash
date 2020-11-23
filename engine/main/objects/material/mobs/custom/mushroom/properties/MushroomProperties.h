//
// Created by roman on 10.10.2020.
//

#ifndef FLASH_MUSHROOMPROPERTIES_H
#define FLASH_MUSHROOMPROPERTIES_H

namespace Mobs {

    /**
     * @brief Struct contains mushroom numeric properties.
     */
    struct MushroomProperties {
        explicit MushroomProperties(float punchPower, float elasticityLevel)
                : punchPower(punchPower), elasticityLevel(elasticityLevel) {}

        /**
         * @brief Mushroom's push power.
         */
        float punchPower;

        /**
         * @brief The percentage of vertical speed that the player will return to when he jumps a mushroom.
         */
        float elasticityLevel;
    };
}

#endif //FLASH_MUSHROOMPROPERTIES_H
