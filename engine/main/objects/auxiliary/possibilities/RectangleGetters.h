//
// Created by roman on 14.09.2020.
//

#ifndef FLASH_RECTANGLEGETTERS_H
#define FLASH_RECTANGLEGETTERS_H

#include "../components/elementary/Size.h"
#include "../components/elementary/point/Point.h"

namespace Possibilities {

    /**
     * @brief The base class of the RectangleGetters class hierarchy.
     * @namespace Possibilities
     *
     * This class defines base RectangleGetters interface.
    */
    class RectangleGetters {
    public:
        RectangleGetters() = default;

        /**
         * @brief Method returns objects's position.
         * @return Objects's position.
         */
        virtual const Components::Point &getPosition() const noexcept = 0;

        /**
         * @brief Method returns objects's size.
         * @return Objects's size.
         */
        virtual const Components::Size &getSize() const noexcept = 0;

        /**
         * @brief Method returns object rotation in degrees.
         * The rotation is always in the range [0, 360].
         *
         * @return Current rotation, in degrees.
         */
        virtual float getRotation() const noexcept = 0;

        virtual ~RectangleGetters() = default;
    };
}

#endif //FLASH_RECTANGLEGETTERS_H
