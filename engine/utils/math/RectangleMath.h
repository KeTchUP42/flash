//
// Created by roman on 16.09.2020.
//

#ifndef FLASH_RECTANGLEMATH_H
#define FLASH_RECTANGLEMATH_H

#include "../../main/objects/auxiliary/possibilities/RectangleInfo.h"
#include "../../main/objects/auxiliary/components/elementary/Speed.h"
#include "../../main/objects/auxiliary/components/elementary/Coordinates.h"
#include "../../main/objects/material/common/MaterialObject.h"

#include <utility>

namespace MathUtils {

    /**
     * @brief Function returns rectangle coordinates.
     * @param rectangle Rectangle rectangle.
     * @return Coordinates.
     */
    Components::Coordinates coordinates(const Possibilities::RectangleInfo *rectangle) noexcept;

    /**
     * @brief Function checks point being inside the rectangle.
     * @param point Some point.
     * @param rectangle Object with rectangle properties.
     * @return Result.
     */
    bool collision(const Components::Point &point, const Possibilities::RectangleInfo &rectangle) noexcept;

    /**
     * @brief Function checks point being inside the rectangle.
     * @param rectangle Object with rectangle properties.
     * @return Result.
     */
    bool collision(float x, float y, const Possibilities::RectangleInfo &rectangle) noexcept;

    /**
     * @brief Function checks point being inside the rectangle.
     * @param rectangle1 Object with rectangle properties.
     * @param rectangle2 Object with rectangle properties.
     * @return Result.
    */
    bool collision(const Possibilities::RectangleInfo &rectangle1, const Possibilities::RectangleInfo &rectangle2) noexcept;

    /**
     * @brief Function returns new point after rotation base point around target point.
     * @return New Point.
     */
    Components::Point pointToPointRotation(const Components::Point &base, float angle, const Components::Point &target) noexcept;

    /**
     * @brief Function returns position offset after rotation base point around target point.
     * @return Speed.
     */
    std::pair<int, int>
    pointToPointRotationOffset(const Components::Point &base, float angle, const Components::Point &target) noexcept;
}
#endif //FLASH_RECTANGLEMATH_H
