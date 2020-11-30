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
        explicit ObstacleProperties(
                const Components::Speed &speed,
                float elasticCoefficient,
                float frictionCoefficient,
                bool isFixed
        ) : MaterialObjectProperties(speed),
            elasticCoefficient(elasticCoefficient),
            frictionCoefficient(frictionCoefficient),
            isFixed(isFixed) {}

        /**
         * @brief Elastic coefficient.
         */
        float elasticCoefficient;

        /**
         * @brief Coefficient of friction.
         */
        float frictionCoefficient;

        /**
         * @brief If this flag is not set, the obstacle will be affected by static effects.
         */
        bool isFixed;
    };
}

#endif //FLASH_OBSTACLEPROPERTIES_H
