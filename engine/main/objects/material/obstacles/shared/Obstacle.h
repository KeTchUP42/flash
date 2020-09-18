//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_OBSTACLE_H
#define FLASH_OBSTACLE_H

#include "../../../auxiliary/possibilities/RectangleSetters.h"
#include "../../shared/MaterialObject.h"

namespace Obstacles {

    /**
     * @brief The base class of the Obstacle class hierarchy. It contains all usefull interfaces.
     * @namespace Obstacles
     *
     * This class defines base Obstacle interface.
    */
    class Obstacle : public Material::MaterialObject,
                     public Possibilities::RectangleSetters {
    public:
        Obstacle() = default;

        virtual ~Obstacle() = default;
    };
}

#endif //FLASH_OBSTACLE_H
