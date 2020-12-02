//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_MATERIALPROPERTIES_H
#define FLASH_MATERIALPROPERTIES_H

#include "../../../auxiliary/components/elementary/speed/Speed.h"

namespace Material {

    /**
     * @brief Struct contains all material numeric properties.
     */
    struct MaterialProperties {
        /**
         * @brief Сonstructor initializes numeric properties.
         */
        explicit MaterialProperties(const Components::Speed &speed) : speed(speed) {}

        /**
         * @brief Object speed.
         */
        Components::Speed speed;
    };
}

#endif //FLASH_MATERIALPROPERTIES_H
