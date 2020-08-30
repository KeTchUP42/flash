//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_COLLISIONPRONE_H
#define FLASH_COLLISIONPRONE_H

namespace Capabilities {

    /**
     * @brief The base class of the CollisionProne class hierarchy.
     * @namespace Capabilities
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
        virtual bool collision(int x, int y) const noexcept = 0;

        virtual ~CollisionProne() = default;
    };
}

#endif //FLASH_COLLISIONPRONE_H
