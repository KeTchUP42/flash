//
// Created by roman on 16.09.2020.
//

#ifndef FLASH_RECTANGLESETTERS_H
#define FLASH_RECTANGLESETTERS_H

#include "../components/elementary/Size.h"
#include "../components/elementary/point/Point.h"

namespace Possibilities {

    class RectangleSetters {
    public:
        RectangleSetters() = default;

        /**
         * @brief Method sets new position point.
         * @param point New Point.
         */
        virtual void setPosition(const Components::Point &point) noexcept = 0;

        /**
         * @brief Method sets new position point.
         * @param x coordinate.
         * @param y coordinate.
         */
        virtual void setPosition(float x, float y) noexcept = 0;

        /**
         * @brief Method sets new object's size.
         * @param size New size.
         */
        virtual void setSize(const Components::Size &size) noexcept = 0;

        /**
         * @brief Method sets new rotation value.
         * @param angle Rotation angle.
         */
        virtual void setRotation(float angle) noexcept = 0;

        virtual ~RectangleSetters() = default;
    };
}

#endif //FLASH_RECTANGLESETTERS_H
