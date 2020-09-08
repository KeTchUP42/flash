//
// Created by roman on 27.08.2020.
//

#ifndef FLASH_MOVABLE_H
#define FLASH_MOVABLE_H

namespace Possibilities {

    /**
     * @brief The base class of the Movable class hierarchy.
     * @namespace Possibilities
     *
     * This class defines base Movable interface.
    */
    class Movable {
    public:
        Movable() = default;

        /**
         * @brief Simple interface method to move object to current coordinates.
         * @param offsetX X offset.
         * @param offsetY Y offset.
         */
        virtual void move(float offsetX, float offsetY) noexcept = 0;

        virtual ~Movable() = default;
    };
}

#endif //FLASH_MOVABLE_H
