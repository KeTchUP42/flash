//
// Created by roman on 22.09.2020.
//

#ifndef FLASH_OBSTACLEPROPERTIES_H
#define FLASH_OBSTACLEPROPERTIES_H

#include "../../../common/properties/MaterialProperties.h"

namespace Obstacles {

    /**
     * @brief Struct contains all obstacle numeric properties.
     */
    struct ObstacleProperties {
        ObstacleProperties(
                float elasticCoefficient,
                float frictionCoefficient,
                bool isFixed
        ) : elasticCoefficient(elasticCoefficient),
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
