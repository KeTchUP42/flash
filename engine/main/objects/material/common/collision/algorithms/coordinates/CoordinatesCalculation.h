//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_COORDINATESCALCULATION_H
#define FLASH_COORDINATESCALCULATION_H

#include "../../../../../auxiliary/possibilities/coordinates/PhysicallySituated.h"

namespace Material {
    /**
     * @brief Analysis helper function.
     * @return Pair of coordinates, max "X" and max "Y".
     */
    Components::Point maxCoordinates(const Possibilities::PhysicallySituated &object) noexcept;

    /**
     * @brief Analysis helper function.
     * @return Pair of coordinates, min "X" and min "Y".
     */
    Components::Point minCoordinates(const Possibilities::PhysicallySituated &object) noexcept;
}


#endif //FLASH_COORDINATESCALCULATION_H
