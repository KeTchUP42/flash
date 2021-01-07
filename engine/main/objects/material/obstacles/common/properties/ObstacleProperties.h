//
// Created by roman on 22.09.2020.
//

#ifndef FLASH_OBSTACLEPROPERTIES_H
#define FLASH_OBSTACLEPROPERTIES_H

#include "../../../common/properties/ParamsTypes.h"

namespace Obstacles {

    /**
     * @brief Struct contains all obstacle numeric properties.
     */
    struct ObstacleProperties {
        ObstacleProperties(
                Material::FRAC_PARAM elasticCoefficient,
                Material::FRAC_PARAM frictionCoefficient,
                Material::BOOL_PARAM isFixed
        ) : elasticCoefficient(elasticCoefficient),
            frictionCoefficient(frictionCoefficient),
            isFixed(isFixed) {}

        /**
         * @brief Elastic coefficient.
         */
        Material::FRAC_PARAM elasticCoefficient;

        /**
         * @brief Coefficient of friction.
         */
        Material::FRAC_PARAM frictionCoefficient;

        /**
         * @brief If this flag is not set, the obstacle will be affected by static effects.
         */
        Material::BOOL_PARAM isFixed;
    };
}

#endif //FLASH_OBSTACLEPROPERTIES_H
