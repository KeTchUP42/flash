//
// Created by roman on 03.10.2020.
//

#ifndef FLASH_COLLISIONALGORITHMS_H
#define FLASH_COLLISIONALGORITHMS_H

#include "../../../../auxiliary/components/elementary/point/Point.h"
#include "../../MaterialObject.h"

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

    /**
     * Function contains moving collision algorithm.
     * After collision event, the main object moves as close as possible to the processed object.
     *
     * @param object Main object.
     * @param processed Processed object.
     * @return True or false.
    */
    bool movingAbscissaCollision(Material::MaterialObject &object, const Material::MaterialObject &processed, float yStep) noexcept;

    /**
     * Function contains moving collision algorithm.
     * After collision event, the main object moves as close as possible to the processed object.
     *
     * @param object Main object.
     * @param processed Processed object.
     * @return True or false.
     */
    bool movingOrdinateCollision(Material::MaterialObject &object, const Material::MaterialObject &processed, float xStep) noexcept;

    /**
     * Function contains moving collision algorithm.
     * After collision event, the main object moves as close as possible to the processed object.
     *
     * @param object Main object.
     * @param objectMinCoordinates Object's min coordinates. Uses for time optimization.
     * @param objectMaxCoordinates Object's max coordinates. Uses for time optimization.
     * @param processed Processed object.
     * @return True or false.
    */
    bool movingAbscissaCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                                 Material::MaterialObject &object, const Material::MaterialObject &processed, float yStep) noexcept;

    /**
     * Function contains moving collision algorithm.
     * After collision event, the main object moves as close as possible to the processed object.
     *
     * @param object Main object.
     * @param objectMinCoordinates Object's min coordinates. Uses for time optimization.
     * @param objectMaxCoordinates Object's max coordinates. Uses for time optimization.
     * @param processed Processed object.
     * @return True or false.
     */
    bool movingOrdinateCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                                 Material::MaterialObject &object, const Material::MaterialObject &processed, float xStep) noexcept;
}

#endif //FLASH_COLLISIONALGORITHMS_H
