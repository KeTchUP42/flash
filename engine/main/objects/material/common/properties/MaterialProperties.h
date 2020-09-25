//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_MATERIALPROPERTIES_H
#define FLASH_MATERIALPROPERTIES_H

#include "../../../auxiliary/components/elementary/Speed.h"

namespace Material {

    /**
     * @brief Struct contains all obstacle numeric properties.
     */
    struct MaterialProperties {
        /**
         * @brief Сonstructor initializes numeric properties.
         */
        explicit MaterialProperties(const Components::Speed &speed, float elasticCoefficient);

        /**
         * @brief Material coefficient.
         */
        float elasticCoefficient;

        /**
         * @brief Object speed.
         */
        Components::Speed speed;
    };
}

#endif //FLASH_MATERIALPROPERTIES_H
