//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_MOVABLE_H
#define FLASH_MOVABLE_H

#include "../components/elementary/speed/Speed.h"

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
         * @brief Method adds some moving speed.
         * @param offsetX X speed.
         * @param offsetY Y speed.
         */
        virtual void addSpeed(float offsetX, float offsetY) noexcept = 0;

        /**
         * @brief Method sets speed.
         * @param speed Move speed.
         */
        virtual void setSpeed(const Components::Speed &speed) noexcept = 0;

        /**
         * @brief Method retuens object move speed.
         * @return Move speed.
         */
        virtual const Components::Speed &getSpeed() const noexcept = 0;

        virtual ~Movable() = default;
    };
}

#endif //FLASH_MOVABLE_H
