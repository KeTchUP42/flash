//
// Created by roman on 23.09.2020.
//

#ifndef FLASH_AREA_H
#define FLASH_AREA_H

#include "point/Point.h"
#include "Size.h"

namespace Components {

    /**
     * @brief Base component.
     * @namespace Components
     *
     * This struct is the base component.
    */
    struct Area {
        explicit Area(const Point &point, const Size &size, float angle)
                : angle(angle), point(point), size(size) {}

        Area() : angle(), point(), size() {}

        float angle;
        Components::Point point;
        Components::Size size;
    };
}

#endif //FLASH_AREA_H
