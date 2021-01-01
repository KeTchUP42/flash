//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_SPEED_H
#define FLASH_SPEED_H

#include <utility>

namespace Components {

    /**
     * @brief The structure is used to represent the object speed on the coordinate plane.
     * @namespace Components
     *
     * This struct is the base component.
    */
    struct Speed {
        /**
         * @brief Constructor converts std::pair<float, float> to Speed.
         * @param speed Speed values.
         */
        explicit Speed(const std::pair<float, float> &speed);

        /**
         * @brief Standard Speed constructor.
         * @param xSpeed Abscissa speed value.
         * @param ySpeed Ordinate speed value.
         */
        Speed(float xSpeed, float ySpeed);

        /**
        * @brief Default constructor.
        */
        Speed() : xSpeed(), ySpeed() {};

        /**
         * @brief Method adds speed offset to speed value.
         * @param offsetX xSpeed offset.
         * @param offsetY ySpeed offset.
         */
        void add(float offsetX, float offsetY) noexcept;

        /**
         * @brief Method checks are xSpeed and ySpeed zero.
         * @return Is zero?
         */
        bool isZero() const noexcept;

        float xSpeed;
        float ySpeed;
    };
}

#endif //FLASH_SPEED_H
