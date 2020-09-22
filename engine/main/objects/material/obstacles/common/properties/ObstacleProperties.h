//
// Created by roman on 22.09.2020.
//

#ifndef FLASH_OBSTACLEPROPERTIES_H
#define FLASH_OBSTACLEPROPERTIES_H

namespace Obstacles {

    /**
     * @brief Struct contains all obstacle numeric properties.
     */
    struct ObstacleProperties {

        /**
         * @brief Сonstructor initializes numeric properties.
         */
        ObstacleProperties(float elasticCoefficient);

        /**
         * @brief Obstacle elastic coefficient.
         */
        float elasticCoefficient;
    };
}

#endif //FLASH_OBSTACLEPROPERTIES_H
