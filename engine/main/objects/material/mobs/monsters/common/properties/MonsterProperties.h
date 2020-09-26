//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_MONSTERPROPERTIES_H
#define FLASH_MONSTERPROPERTIES_H

#include "../../../../common/properties/MaterialObjectProperties.h"

namespace Mobs {

    /**
     * @brief Struct contains all monster numeric properties.
     */
    struct MonsterProperties : Material::MaterialObjectProperties {

        explicit MonsterProperties(const Components::Speed &speed)
                : Material::MaterialObjectProperties(speed) {}
    };
}

#endif //FLASH_MONSTERPROPERTIES_H
