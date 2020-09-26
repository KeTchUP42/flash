//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_OBSTACLE_H
#define FLASH_OBSTACLE_H

#include "../../../auxiliary/possibilities/RectangleSetters.h"
#include "../../../auxiliary/possibilities/Physical.h"
#include "properties/ObstacleProperties.h"
#include "../../common/MaterialObject.h"

namespace Obstacles {

    /**
     * @brief The base class of the Obstacle class hierarchy. It contains all usefull interfaces.
     * @namespace Obstacles
     *
     * This class defines base Obstacle interface.
    */
    class Obstacle : public Material::MaterialObject,
                     public Possibilities::RectangleSetters,
                     public Possibilities::Physical<Obstacles::ObstacleProperties> {
    public:
        /**
         * @brief Base obstacle constructor.
         * @param properties Object with obstacle properties.
         */
        Obstacle(const ObstacleProperties &properties) : _properties(properties) {};

        virtual ~Obstacle() = default;

    protected:
        ObstacleProperties _properties;
    };
}

#endif //FLASH_OBSTACLE_H
