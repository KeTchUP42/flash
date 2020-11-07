//
// Created by roman on 01.11.2020.
//

#ifndef FLASH_ROTATINGMATH_H
#define FLASH_ROTATINGMATH_H

#include "../elementary/point/Point.h"
#include <utility>

namespace Components {

    namespace Math {

        /**
         * @brief Function returns new point after rotation base point around target point.
         * @return New Point.
         */
        Point pointToPointRotation(const Point &base, float angle, const Point &target) noexcept;

        /**
         * @brief Function returns position offset after rotation base point around target point.
         * @return Speed.
         */
        std::pair<float, float>
        pointToPointRotationOffset(const Point &base, float angle, const Point &target) noexcept;
    }
}

#endif //FLASH_ROTATINGMATH_H
