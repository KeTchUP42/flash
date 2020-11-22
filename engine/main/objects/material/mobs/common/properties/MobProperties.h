//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_MOBPROPERTIES_H
#define FLASH_MOBPROPERTIES_H

#include "../../../common/properties/MaterialObjectProperties.h"

namespace Mobs {

    /**
     * @brief Struct contains all mob numeric properties.
     */
    struct MobProperties : public Material::MaterialObjectProperties {
        explicit MobProperties(const Components::Speed &speed, float maxHealthPoints, float healthPoints)
                : Material::MaterialObjectProperties(speed), maxHealthPoints(maxHealthPoints), healthPoints(healthPoints) {}

        float maxHealthPoints;
        float healthPoints;
    };
}

#endif //FLASH_MOBPROPERTIES_H
