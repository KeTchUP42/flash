//
// Created by roman on 10.10.2020.
//

#ifndef FLASH_COORDINATES_H
#define FLASH_COORDINATES_H

#include <vector>
#include "../point/Point.h"

namespace Components {

    /**
     * @brief Struct with coordinates.
     */
    struct Coordinates {
        /**
         * @brief Default constructor.
         */
        Coordinates() = default;

        /**
         * @brief Constructor inits points list.
         * @param coordinates Points list.
         */
        Coordinates(const std::vector<Components::Point> &coordinates) : list(coordinates) {}

        /**
         * @brief Points list.
         */
        std::vector<Components::Point> list;
    };
}

#endif //FLASH_COORDINATES_H
