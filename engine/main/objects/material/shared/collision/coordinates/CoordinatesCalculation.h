//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_COORDINATESCALCULATION_H
#define FLASH_COORDINATESCALCULATION_H

#include "../../../../auxiliary/components/elementary/point/Point.h"
#include "../../../../auxiliary/possibilities/RectangleGetters.h"

namespace Material {
    /**
     * @brief Analysis helper function.
     * @return Pair of coordinates, max "X" and max "Y".
     */
    Components::Point maxCoordinates(const Possibilities::RectangleGetters &rectangle);

    /**
     * @brief Analysis helper function.
     * @return Pair of coordinates, min "X" and min "Y".
     */
    Components::Point minCoordinates(const Possibilities::RectangleGetters &rectangle);
}


#endif //FLASH_COORDINATESCALCULATION_H
