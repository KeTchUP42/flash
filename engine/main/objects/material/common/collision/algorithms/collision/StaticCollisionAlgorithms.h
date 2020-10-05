//
// Created by roman on 05.10.2020.
//

#ifndef FLASH_STATICCOLLISIONALGORITHMS_H
#define FLASH_STATICCOLLISIONALGORITHMS_H

#include "../../../../../auxiliary/components/elementary/point/Point.h"
#include "../../../MaterialObject.h"

namespace Material {

    /**
     * @brief Function contains static collision algorithm.
     * @param object Main object.
     * @param processed Processed object.
     * @return True or false.
     */
    bool staticAbscissaCollision(const Material::MaterialObject &object, const Material::MaterialObject &processed) noexcept;

    /**
     * @brief Function contains static collision algorithm.
     * @param object Main object.
     * @param processed Processed object.
     * @return True or false.
     */
    bool staticOrdinateCollision(const Material::MaterialObject &object, const Material::MaterialObject &processed) noexcept;

    /**
     * @brief Function contains static collision algorithm.
     * @param object Main object.
     * @param objectMinCoordinates Object's min coordinates. Uses for time optimization.
     * @param objectMaxCoordinates Object's max coordinates. Uses for time optimization.
     * @param processed Processed object.
     * @return True or false.
     */
    bool staticAbscissaCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                                 const Material::MaterialObject &object, const Material::MaterialObject &processed) noexcept;

    /**
     * @brief Function contains static collision algorithm.
     * @param object Main object.
     * @param objectMinCoordinates Object's min coordinates. Uses for time optimization.
     * @param objectMaxCoordinates Object's max coordinates. Uses for time optimization.
     * @param processed Processed object.
     * @return True or false.
     */
    bool staticOrdinateCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                                 const Material::MaterialObject &object, const Material::MaterialObject &processed) noexcept;

}

#endif //FLASH_STATICCOLLISIONALGORITHMS_H
