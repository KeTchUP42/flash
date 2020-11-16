//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_MATERIALOBJECTPROPERTIES_H
#define FLASH_MATERIALOBJECTPROPERTIES_H

#include "../../../auxiliary/components/elementary/speed/Speed.h"

namespace Material {

    /**
     * @brief Struct contains all obstacle numeric properties.
     */
    struct MaterialObjectProperties {
        /**
         * @brief Сonstructor initializes numeric properties.
         */
        explicit MaterialObjectProperties(const Components::Speed &speed) : speed(speed) {}

        /**
         * @brief Object speed.
         */
        Components::Speed speed;

        /**
         * @brief If the flag is set, the object will be removed from the unifier when the frame is completed.
         */
        bool isRemovable = false;
    };
}

#endif //FLASH_MATERIALOBJECTPROPERTIES_H
