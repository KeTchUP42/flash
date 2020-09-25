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
    struct ObstacleProperties : public Material::MaterialProperties {
        explicit ObstacleProperties(const Components::Speed &speed, float elasticCoefficient);
    };
}

#endif //FLASH_OBSTACLEPROPERTIES_H
