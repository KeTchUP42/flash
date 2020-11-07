//
// Created by roman on 05.10.2020.
//

#ifndef FLASH_STATICCOLLISIONALGORITHMS_H
#define FLASH_STATICCOLLISIONALGORITHMS_H

#include "../../../MaterialObject.h"

namespace Material {

    /**
     * @brief Function contains static collision algorithm.
     * @param object1 First processed object.
     * @param object2 Second processed object.
     * @return True or false.
     */
    bool staticAbscissaCollision(const Material::MaterialObject &object1, const Material::MaterialObject &object2) noexcept;

    /**
     * @brief Function contains static collision algorithm.
     * @param object1 First processed object.
     * @param object2 Second processed object.
     * @return True or false.
     */
    bool staticOrdinateCollision(const Material::MaterialObject &object1, const Material::MaterialObject &object2) noexcept;

    /**
     * @brief Function contains static collision algorithm.
     * @param objectMinCoordinates Object's min coordinates. Uses for time optimization.
     * @param objectMaxCoordinates Object's max coordinates. Uses for time optimization.
     * @param object1 First processed object.
     * @param object2 Second processed object.
     * @return True or false.
     */
    bool staticAbscissaCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                                 const Material::MaterialObject &object1, const Material::MaterialObject &object2) noexcept;

    /**
     * @brief Function contains static collision algorithm.
     * @param objectMinCoordinates Object's min coordinates. Uses for time optimization.
     * @param objectMaxCoordinates Object's max coordinates. Uses for time optimization.
     * @param object1 First processed object.
     * @param object2 Second processed object.
     * @return True or false.
     */
    bool staticOrdinateCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                                 const Material::MaterialObject &object1, const Material::MaterialObject &object2) noexcept;
}

#endif //FLASH_STATICCOLLISIONALGORITHMS_H
