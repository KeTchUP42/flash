//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_PLAYERPROPERTIES_H
#define FLASH_PLAYERPROPERTIES_H

#include "../../../../common/properties/MaterialObjectProperties.h"

namespace Mobs {

    /**
     * @brief Struct contains all player numeric properties.
     */
    struct PlayerProperties : public Material::MaterialObjectProperties {

        explicit PlayerProperties(const Components::Speed &speed)
                : MaterialObjectProperties(speed) {}
    };
}

#endif //FLASH_PLAYERPROPERTIES_H
