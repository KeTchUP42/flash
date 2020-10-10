//
// Created by roman on 10.10.2020.
//

#ifndef FLASH_COORDINATES_H
#define FLASH_COORDINATES_H

#include "point/Point.h"

namespace Components {

    /**
     * @brief Struct with all rectangle coordinates.
     */
    struct Coordinates {
        explicit Coordinates(const Components::Point &point1, const Components::Point &point2,
                             const Components::Point &point3, const Components::Point &point4)
                : point_1(point1), point_2(point2), point_3(point3), point_4(point4) {}

        Coordinates() {}

        Components::Point point_1;
        Components::Point point_2;
        Components::Point point_3;
        Components::Point point_4;
    };
}

#endif //FLASH_COORDINATES_H
