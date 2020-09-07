//
// Created by roman on 06.09.2020.
//

#ifndef FLASH_ROTATABLE_H
#define FLASH_ROTATABLE_H

namespace Possibilities {

    /**
     * @brief The base class of the Rotatable class hierarchy.
     * @namespace Possibilities
     *
     * This class defines base Rotatable interface.
    */
    class Rotatable {
    public:
        Rotatable() = default;

        /**
         * @brief Method rotates object around its coordinates.
         */
        virtual void rotate(float angle) noexcept = 0;

        /**
         * @brief Method rotates object around given coordinates.
         * @param angle Rotate angle.
         * @param x coordinate.
         * @param y coordinate.
         */
        virtual void rotate(float angle, int x, int y) noexcept = 0;

        virtual ~Rotatable() = default;
    };
}

#endif //FLASH_ROTATABLE_H
