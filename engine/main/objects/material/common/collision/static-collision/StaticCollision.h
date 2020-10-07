//
// Created by roman on 05.10.2020.
//

#ifndef FLASH_STATICCOLLISION_H
#define FLASH_STATICCOLLISION_H

#include "../../MaterialObject.h"
#include "../algorithms/coordinates/CoordinatesCalculation.h"
#include "../algorithms/collision/StaticCollisionAlgorithms.h"

#include <list>

namespace Material {

    class StaticCollision {
    public:
        template<class Type>
        Type *abscissaMoveAble(MaterialObject *object, const std::list<std::shared_ptr<Type>> &objects) const noexcept;

        template<class Type>
        Type *ordinateMoveAble(MaterialObject *object, const std::list<std::shared_ptr<Type>> &objects) const noexcept;

        bool abscissaMoveAble(Material::MaterialObject *object, Material::MaterialObject *processed) const noexcept;

        bool ordinateMoveAble(Material::MaterialObject *object, Material::MaterialObject *processed) const noexcept;
    };

    template<class Type>
    Type *Material::StaticCollision::
    abscissaMoveAble(MaterialObject *object, const std::list<std::shared_ptr<Type>> &objects) const noexcept {
        Components::Point objectMinCoordinates = minCoordinates(*object);
        Components::Point objectMaxCoordinates = maxCoordinates(*object);

        for (const std::shared_ptr<Type> &processed : objects) {

            if (processed.get() == object) continue;

            if (staticAbscissaCollision(objectMinCoordinates, objectMaxCoordinates, *object, *processed)) {
                return processed.get();
            }
        }
        return nullptr;
    }

    template<class Type>
    Type *Material::StaticCollision::
    ordinateMoveAble(MaterialObject *object, const std::list<std::shared_ptr<Type>> &objects) const noexcept {
        Components::Point objectMinCoordinates = minCoordinates(*object);
        Components::Point objectMaxCoordinates = maxCoordinates(*object);

        for (const std::shared_ptr<Type> &processed : objects) {

            if (processed.get() == object) continue;

            if (staticOrdinateCollision(objectMinCoordinates, objectMaxCoordinates, *object, *processed)) {
                return processed.get();
            }
        }
        return nullptr;
    }
}

#endif //FLASH_STATICCOLLISION_H
