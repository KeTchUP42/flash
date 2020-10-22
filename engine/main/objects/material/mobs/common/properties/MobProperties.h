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

        /**
         * @brief If the flag is set, the object will be removed from the unifier when the frame is completed.
         */
        bool isRemovable = false;
    };
}

#endif //FLASH_MOBPROPERTIES_H
