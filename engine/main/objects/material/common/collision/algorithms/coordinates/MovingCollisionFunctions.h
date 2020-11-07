//
// Created by roman on 03.11.2020.
//

#ifndef FLASH_MOVINGCOLLISIONFUNCTIONS_H
#define FLASH_MOVINGCOLLISIONFUNCTIONS_H

#include "../../../../../auxiliary/possibilities/coordinates/PhysicallySituated.h"

namespace Material {

    /**
     * @brief Function returns vector of collision needed points.
     * @param object Target object.
     * @param ordinateVerge Min and max ordinate values.
     * @param moveSide True - right, false - left.
     * @return Vector of need points.
     */
    std::vector<Components::Point>
    pickoutNodulesVertical(const Possibilities::PhysicallySituated &object, const std::pair<float, float> &ordinateVerge, bool moveSide) noexcept;

    /**
     * @brief Function returns vector of collision needed points.
     * @param object Target object.
     * @param abscissaVerge Min and max abscissa values.
     * @param moveSide True - down, false - up.
     * @return Vector of need points.
     */
    std::vector<Components::Point>
    pickoutNodulesHorizontal(const Possibilities::PhysicallySituated &object, const std::pair<float, float> &abscissaVerge, bool moveSide) noexcept;
}

#endif //FLASH_MOVINGCOLLISIONFUNCTIONS_H
