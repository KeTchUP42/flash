//
// Created by roman on 16.09.2020.
//

#ifndef FLASH_CALCULATIONS_H
#define FLASH_CALCULATIONS_H

#include "../../main/objects/auxiliary/possibilities/RectangleGetters.h"
#include "../../main/objects/auxiliary/components/elementary/Speed.h"

#include <utility>

namespace OtherUtils {

    /**
     * @brief Function checks point being inside the rectangle.
     * @param point Some point.
     * @param rectangle Object with rectangle properties.
     * @return Result.
     */
    bool collision(const Components::Point &point, const Possibilities::RectangleGetters &rectangle) noexcept;

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
#endif //FLASH_CALCULATIONS_H
