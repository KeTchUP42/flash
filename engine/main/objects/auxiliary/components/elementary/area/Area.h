//
// Created by roman on 23.09.2020.
//

#ifndef FLASH_AREA_H
#define FLASH_AREA_H

#include "../point/Point.h"
#include "../Size.h"
#include "../../../possibilities/RectangleGetters.h"

namespace Components {

    /**
     * @brief Base component.
     * @namespace Components
     *
     * This struct is the base component.
    */
    struct Area : public Possibilities::RectangleGetters {
        explicit Area(const Point &point, const Size &size, float angle)
                : angle(angle), point(point), size(size) {}

        Area() : angle(), point(), size() {}

        const Point &getPosition() const noexcept override;

        const Size &getSize() const noexcept override;

        float getRotation() const noexcept override;

        float angle;
        Components::Point point;
        Components::Size size;
    };
}

#endif //FLASH_AREA_H
