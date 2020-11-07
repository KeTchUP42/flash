
//
// Created by roman on 02.11.2020.
//

#ifndef FLASH_COMMONCOLLISIONALGORITHMS_H
#define FLASH_COMMONCOLLISIONALGORITHMS_H

#define _USE_MATH_DEFINES

#include <math.h>

#include "../../../../../auxiliary/possibilities/coordinates/PhysicallySituated.h"
#include "../../../../../auxiliary/possibilities/rectangle/MaterialRectangle.h"
#include "../../../MaterialObject.h"

namespace Material {

    /**
     * @brief Function checks point being inside the object.
     * @param object Object with object properties.
     * @return Result.
    */
    bool collision(float x, float y, const Possibilities::PhysicallySituated &object) noexcept;

    /**
     * @brief Function checks objects static collision.
     * @param object1 Object with сoordinates properties.
     * @param object2 Object with сoordinates properties.
     * @return Result.
    */
    bool collision(const Possibilities::PhysicallySituated &object1, const Possibilities::PhysicallySituated &object2) noexcept;

    /**
     * @brief Function checks objects static collision. It was optimized for rectangle like objects.
     * @param object1 Object with сoordinates properties.
     * @param object2 Object with сoordinates properties.
     * @return Result.
    */
    template<class RectangleType1, class RectangleType2>
    bool RectangleCollision(const RectangleType1 &object1, const RectangleType2 &object2) noexcept {

        float rectangle1Diagonal = std::sqrt(std::pow(object1.getSize().width, 2) + std::pow(object1.getSize().height, 2));
        float rectangle2Diagonal = std::sqrt(std::pow(object2.getSize().width, 2) + std::pow(object2.getSize().height, 2));

        float vectorModule = std::sqrt(std::pow(object1.getPosition().x - object2.getPosition().x, 2) +
                                       std::pow(object1.getPosition().y - object2.getPosition().y, 2));

        if (vectorModule > (rectangle1Diagonal + rectangle2Diagonal)) return false;
        return Material::collision(object1, object2);
    }

}

#endif //FLASH_COMMONCOLLISIONALGORITHMS_H
