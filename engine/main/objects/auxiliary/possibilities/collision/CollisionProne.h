//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_COLLISIONPRONE_H
#define FLASH_COLLISIONPRONE_H

#include "../coordinates/PhysicallySituated.h"

namespace Possibilities {

    /**
     * @brief The base class of the CollisionProne class hierarchy.
     * @namespace Possibilities
     *
     * This class defines base CollisionProne interface.
    */
    class CollisionProne {
    public:
        CollisionProne() = default;

        /**
         * @brief Simple interface method to check object collision to current coordinates.
         * @param x coordinate.
         * @param y coordinate.
         */
        virtual bool collision(float x, float y) const noexcept = 0;

        /**
         * @brief Method checks object collision to other object.
         * @param object Other object.
         */
        virtual bool collision(const Possibilities::PhysicallySituated &object) const noexcept = 0;

        virtual ~CollisionProne() = default;
    };
}

#endif //FLASH_COLLISIONPRONE_H
