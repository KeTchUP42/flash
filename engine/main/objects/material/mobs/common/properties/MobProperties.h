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
    struct MobProperties : Material::MaterialObjectProperties {

        explicit MobProperties(float healthPoints, const Components::Speed &speed)
                : Material::MaterialObjectProperties(speed), healthPoints(healthPoints) {}

        float healthPoints;
    };
}

#endif //FLASH_MOBPROPERTIES_H
