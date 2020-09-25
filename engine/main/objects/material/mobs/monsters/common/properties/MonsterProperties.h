//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_MONSTERPROPERTIES_H
#define FLASH_MONSTERPROPERTIES_H

#include "../../../../common/properties/MaterialProperties.h"

namespace Mobs {

    /**
     * @brief Struct contains all monster numeric properties.
     */
    struct MonsterProperties : Material::MaterialProperties {
        explicit MonsterProperties(const Components::Speed &speed, float elasticCoefficient);
    };
}

#endif //FLASH_MONSTERPROPERTIES_H
