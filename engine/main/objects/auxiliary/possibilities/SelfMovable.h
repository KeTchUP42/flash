//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_SELFMOVABLE_H
#define FLASH_SELFMOVABLE_H

#include "../components/elementary/Speed.h"

namespace Possibilities {

    /**
     * @brief The base class of the SelfMovable class hierarchy.
     * @namespace Possibilities
     *
     * This class defines base SelfMovable interface.
    */
    template<class Unifier>
    class SelfMovable {
    public:
        SelfMovable() = default;

        /**
         * @brief Method do self move.
         */
        virtual void selfMove(Unifier *unifier) = 0;

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

        virtual ~SelfMovable() = default;
    };
}

#endif //FLASH_SELFMOVABLE_H
