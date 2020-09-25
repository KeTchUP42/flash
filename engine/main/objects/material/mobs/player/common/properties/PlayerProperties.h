//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_PLAYERPROPERTIES_H
#define FLASH_PLAYERPROPERTIES_H

#include "../../../../common/properties/MaterialProperties.h"

namespace Mobs {

    /**
     * @brief Struct contains all player numeric properties.
     */
    struct PlayerProperties : public Material::MaterialProperties {
        explicit PlayerProperties(const Components::Speed &speed, float elasticCoefficient);
    };
}

#endif //FLASH_PLAYERPROPERTIES_H
