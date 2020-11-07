//
// Created by roman on 05.10.2020.
//

#include "StaticCollisionAlgorithms.h"
#include "../coordinates/CoordinatesCalculation.h"

bool Material::
staticAbscissaCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                        const Material::MaterialObject &object1, const Material::MaterialObject &object2) noexcept {

    Components::Point processedMinCoordinates = minCoordinates(object2);
    Components::Point processedMaxCoordinates = maxCoordinates(object2);

    if (!((((objectMinCoordinates.y >= processedMinCoordinates.y) && (objectMinCoordinates.y <= processedMaxCoordinates.y)) ||
           ((objectMaxCoordinates.y >= processedMinCoordinates.y) && (objectMaxCoordinates.y <= processedMaxCoordinates.y))) ||
          (((processedMinCoordinates.y >= objectMinCoordinates.y) && (processedMinCoordinates.y <= objectMaxCoordinates.y)) ||
           ((processedMaxCoordinates.y >= objectMinCoordinates.y) && (processedMaxCoordinates.y <= objectMaxCoordinates.y)))))
        return false; //Takes only processed with valid position.

    //Optimization.
    if (processedMaxCoordinates.x > objectMaxCoordinates.x) {
        if (processedMinCoordinates.x - objectMaxCoordinates.x > 0) return false;
    } else {
        if (objectMinCoordinates.x - processedMaxCoordinates.x > 0) return false;
    }
    return object1.collision(object2);
}

bool Material::
staticOrdinateCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                        const Material::MaterialObject &object1, const Material::MaterialObject &object2) noexcept {

    Components::Point processedMinCoordinates = minCoordinates(object2);
    Components::Point processedMaxCoordinates = maxCoordinates(object2);

    if (!((((objectMinCoordinates.x >= processedMinCoordinates.x) && (objectMinCoordinates.x <= processedMaxCoordinates.x)) ||
           ((objectMaxCoordinates.x >= processedMinCoordinates.x) && (objectMaxCoordinates.x <= processedMaxCoordinates.x))) ||
          (((processedMinCoordinates.x >= objectMinCoordinates.x) && (processedMinCoordinates.x <= objectMaxCoordinates.x)) ||
           ((processedMaxCoordinates.x >= objectMinCoordinates.x) && (processedMaxCoordinates.x <= objectMaxCoordinates.x)))))
        return false; //Takes only processed with valid position.

    //Optimization.
    if (processedMaxCoordinates.y > objectMaxCoordinates.y) {
        if (processedMinCoordinates.y - objectMaxCoordinates.y > 0) return false;
    } else {
        if (objectMinCoordinates.y - processedMaxCoordinates.y > 0) return false;
    }
    return object1.collision(object2);
}

bool Material::
staticAbscissaCollision(const Material::MaterialObject &object1, const Material::MaterialObject &object2) noexcept {
    return staticAbscissaCollision(minCoordinates(object1), maxCoordinates(object1), object1, object2);
}

bool Material::
staticOrdinateCollision(const Material::MaterialObject &object1, const Material::MaterialObject &object2) noexcept {
    return staticOrdinateCollision(minCoordinates(object1), maxCoordinates(object1), object1, object2);
}
