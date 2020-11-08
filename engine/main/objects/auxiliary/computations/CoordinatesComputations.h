//
// Created by roman on 16.09.2020.
//

#ifndef FLASH_RECTANGLEMATH_H
#define FLASH_RECTANGLEMATH_H

#include "../possibilities/rectangle/RectangleGetters.h"
#include "../components/elementary/coordinates/Coordinates.h"

namespace Computations {

    /**
     * @brief Function returns rectangle coordinates.
     * @param rectangle Rectangle rectangle.
     * @return Coordinates.
     */
    Components::Coordinates coordinates(Possibilities::RectangleGetters *rectangle) noexcept;
}
#endif //FLASH_RECTANGLE_H
