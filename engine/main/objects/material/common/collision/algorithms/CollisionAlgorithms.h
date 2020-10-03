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
    bool staticAbscissaMoveAble(const Material::MaterialObject &object, const Material::MaterialObject &processed) noexcept;

    /**
     * @brief Function contains static collision algorithm.
     * @param object Main object.
     * @param processed Processed object.
     * @return True or false.
     */
    bool staticOrdinateMoveAble(const Material::MaterialObject &object, const Material::MaterialObject &processed) noexcept;

    /**
     * @brief Function contains static collision algorithm.
     * @param object Main object.
     * @param objectMinCoordinates Object's min coordinates. For time optimization.
     * @param objectMaxCoordinates Object's max coordinates. For time optimization.
     * @param processed Processed object.
     * @return True or false.
     */
    bool staticAbscissaMoveAble(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                                const Material::MaterialObject &object, const Material::MaterialObject &processed) noexcept;

    /**
     * @brief Function contains static collision algorithm.
     * @param object Main object.
     * @param objectMinCoordinates Object's min coordinates. For time optimization.
     * @param objectMaxCoordinates Object's max coordinates. For time optimization.
     * @param processed Processed object.
     * @return True or false.
     */
    bool staticOrdinateMoveAble(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                                const Material::MaterialObject &object, const Material::MaterialObject &processed) noexcept;

    /**
     * @brief Function contains moving collision algorithm.
     * @param object Main object.
     * @param processed Processed object.
     * @return True or false.
    */
    bool movingAbscissaMoveAble(const Material::MaterialObject &object, const Material::MaterialObject &processed, float yStep) noexcept;

    /**
     * @brief Function contains moving collision algorithm.
     * @param object Main object.
     * @param processed Processed object.
     * @return True or false.
     */
    bool movingOrdinateMoveAble(const Material::MaterialObject &object, const Material::MaterialObject &processed, float xStep) noexcept;

    /**
     * @brief Function contains moving collision algorithm.
     * @param object Main object.
     * @param objectMinCoordinates Object's min coordinates. For time optimization.
     * @param objectMaxCoordinates Object's max coordinates. For time optimization.
     * @param processed Processed object.
     * @return True or false.
    */
    bool movingAbscissaMoveAble(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                                const Material::MaterialObject &object, const Material::MaterialObject &processed, float yStep) noexcept;

    /**
     * @brief Function contains moving collision algorithm.
     * @param object Main object.
     * @param objectMinCoordinates Object's min coordinates. For time optimization.
     * @param objectMaxCoordinates Object's max coordinates. For time optimization.
     * @param processed Processed object.
     * @return True or false.
     */
    bool movingOrdinateMoveAble(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                                const Material::MaterialObject &object, const Material::MaterialObject &processed, float xStep) noexcept;
}

#endif //FLASH_COLLISIONALGORITHMS_H
