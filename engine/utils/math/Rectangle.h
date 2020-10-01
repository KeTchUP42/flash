//
// Created by roman on 16.09.2020.
//

#ifndef FLASH_RECTANGLE_H
#define FLASH_RECTANGLE_H

#include "../../main/objects/auxiliary/possibilities/RectangleGetters.h"
#include "../../main/objects/auxiliary/components/elementary/Speed.h"

#include <utility>

namespace MathUtils {

    /**
     * @brief Struct with all rectangle coordinates.
     */
    struct RectangleCoordinates {
        explicit RectangleCoordinates(const Components::Point &point1, const Components::Point &point2,
                                      const Components::Point &point3, const Components::Point &point4);

        Components::Point point_1;
        Components::Point point_2;
        Components::Point point_3;
        Components::Point point_4;
    };

    /**
     * @brief Function returns rectangle coordinates.
     * @param rectangle Rectangle object.
     * @return Coordinates.
     */
    RectangleCoordinates coordinates(const Possibilities::RectangleGetters &rectangle) noexcept;

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
#endif //FLASH_RECTANGLE_H
