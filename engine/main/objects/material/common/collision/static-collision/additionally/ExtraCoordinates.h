//
// Created by roman on 21.09.2020.
//

#ifndef FLASH_EXTRACOORDINATES_H
#define FLASH_EXTRACOORDINATES_H

#include "../../../../../auxiliary/components/elementary/point/Point.h"
#include "../../../../../auxiliary/possibilities/RectangleGetters.h"
#include "../../../../../../../utils/other/Calculations.h"

#include <vector>

namespace Material {

    /**
     * @brief Function returns points without "absentXValue" `X` value.
     */
    std::vector<Components::Point>
    extremeCoordinatesAbscissa(const Possibilities::RectangleGetters &rectangle, float absentXValue) noexcept;

    /**
     * @brief Function returns points without "absentYValue" `Y` value.
     */
    std::vector<Components::Point>
    extremeCoordinatesOrdinate(const Possibilities::RectangleGetters &rectangle, float absentYValue) noexcept;
}
#endif //FLASH_EXTRACOORDINATES_H
