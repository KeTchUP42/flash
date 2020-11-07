//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_SPEED_H
#define FLASH_SPEED_H

#include <utility>

namespace Components {

    /**
     * @brief The structure is used to represent the object velocity on the coordinate plane.
     * @namespace Components
     *
     * This struct is the base component.
    */
    struct Speed {
        explicit Speed(float xSpeed, float ySpeed)
                : xSpeed(xSpeed), ySpeed(ySpeed) {}

        Speed(const std::pair<float, float> &speed)
                : xSpeed(speed.first), ySpeed(speed.second) {}

        Speed() : xSpeed(), ySpeed() {};

        /**
         * @brief Method adds speed offset to speed value.
         * @param offsetX xSpeed offset.
         * @param offsetY ySpeed offset.
         */
        void add(float offsetX, float offsetY) noexcept;

        float xSpeed;
        float ySpeed;
    };
}

#endif //FLASH_SPEED_H
