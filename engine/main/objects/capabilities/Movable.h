//
// Created by roman on 27.08.2020.
//

#ifndef FLASH_MOVABLE_H
#define FLASH_MOVABLE_H

namespace Capabilities {

    /**
     * @brief The base class of the Movable class hierarchy.
     * @namespace Capabilities
     *
     * This class defines base Movable interface.
    */
    class Movable {
    public:
        Movable() = default;

        /**
         * @brief Simple interface method to move object to current coordinates.
         * @param xlength Coordinates to move on X.
         * @param ylength Coordinates to move on Y.
         */
        virtual void move(int xlength, int ylength) noexcept = 0;

        virtual ~Movable() = default;
    };
}

#endif //FLASH_MOVABLE_H
