//
// Created by roman on 22.09.2020.
//

#ifndef FLASH_OBSTACLEPROPERTIES_H
#define FLASH_OBSTACLEPROPERTIES_H

#include "../../../common/properties/MaterialObjectProperties.h"

namespace Obstacles {

    /**
     * @brief Struct contains all obstacle numeric properties.
     */
    struct ObstacleProperties : public Material::MaterialObjectProperties {

        explicit ObstacleProperties(const Components::Speed &speed, float elasticCoefficient)
                : MaterialObjectProperties(speed), elasticCoefficient(elasticCoefficient) {}

        /**
         * @brief Material coefficient.
         */
        float elasticCoefficient;
    };
}

#endif //FLASH_OBSTACLEPROPERTIES_H
