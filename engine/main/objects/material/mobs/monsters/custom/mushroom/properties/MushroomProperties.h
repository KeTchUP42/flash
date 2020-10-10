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

        float punchPower;
        float elasticityLevel;
    };
}

#endif //FLASH_MUSHROOMPROPERTIES_H
