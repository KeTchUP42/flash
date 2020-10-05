//
// Created by roman on 05.10.2020.
//

#include "StaticCollisionAlgorithms.h"
#include "../coordinates/ExtremeCoordinates.h"
#include "../coordinates/CoordinatesCalculation.h"

bool Material::
staticAbscissaCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                        const Material::MaterialObject &object, const Material::MaterialObject &processed) noexcept {

    Components::Point processedMinCoordinates = minCoordinates(processed);
    Components::Point processedMaxCoordinates = maxCoordinates(processed);

    if (!((((objectMinCoordinates.y >= processedMinCoordinates.y) && (objectMinCoordinates.y <= processedMaxCoordinates.y)) ||
           ((objectMaxCoordinates.y >= processedMinCoordinates.y) && (objectMaxCoordinates.y <= processedMaxCoordinates.y))) ||
          (((processedMinCoordinates.y >= objectMinCoordinates.y) && (processedMinCoordinates.y <= objectMaxCoordinates.y)) ||
           ((processedMaxCoordinates.y >= objectMinCoordinates.y) && (processedMaxCoordinates.y <= objectMaxCoordinates.y)))))
        return false; //Takes only processed with valid position.

    bool objectCloserToOrigin = processedMaxCoordinates.x > objectMaxCoordinates.x;

    //Optimization.
    if (objectCloserToOrigin) {
        if (processedMinCoordinates.x - objectMaxCoordinates.x > 0) return false;
    } else {
        if (objectMinCoordinates.x - processedMaxCoordinates.x > 0) return false;
    }

    float objectSuperfluousX = ((objectCloserToOrigin) ? objectMinCoordinates.x : objectMaxCoordinates.x);

    for (const Components::Point &point : extremeCoordinatesAbscissa(object, objectSuperfluousX)) {
        if (processed.collision(point.x, point.y)) {
            return true;
        }
    }

    float processedSuperfluousX = ((objectCloserToOrigin) ? processedMaxCoordinates.x : processedMinCoordinates.x);

    for (const Components::Point &point : extremeCoordinatesAbscissa(processed, processedSuperfluousX)) {
        if (object.collision(point.x, point.y)) {
            return true;
        }
    }
    return false;
}

bool Material::
staticOrdinateCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                        const Material::MaterialObject &object, const Material::MaterialObject &processed) noexcept {

    Components::Point processedMinCoordinates = minCoordinates(processed);
    Components::Point processedMaxCoordinates = maxCoordinates(processed);

    if (!((((objectMinCoordinates.x >= processedMinCoordinates.x) && (objectMinCoordinates.x <= processedMaxCoordinates.x)) ||
           ((objectMaxCoordinates.x >= processedMinCoordinates.x) && (objectMaxCoordinates.x <= processedMaxCoordinates.x))) ||
          (((processedMinCoordinates.x >= objectMinCoordinates.x) && (processedMinCoordinates.x <= objectMaxCoordinates.x)) ||
           ((processedMaxCoordinates.x >= objectMinCoordinates.x) && (processedMaxCoordinates.x <= objectMaxCoordinates.x)))))
        return false; //Takes only processed with valid position.

    bool objectCloserToOrigin = processedMaxCoordinates.y > objectMaxCoordinates.y;

    //Optimization.
    if (objectCloserToOrigin) {
        if (processedMinCoordinates.y - objectMaxCoordinates.y > 0) return false;
    } else {
        if (objectMinCoordinates.y - processedMaxCoordinates.y > 0) return false;
    }

    float objectSuperfluousY = ((objectCloserToOrigin) ? objectMinCoordinates.y : objectMaxCoordinates.y);

    for (const Components::Point &point : extremeCoordinatesOrdinate(object, objectSuperfluousY)) {
        if (processed.collision(point.x, point.y)) {
            return true;
        }
    }

    float processedSuperfluousY = ((objectCloserToOrigin) ? processedMaxCoordinates.y : processedMinCoordinates.y);

    for (const Components::Point &point : extremeCoordinatesOrdinate(processed, processedSuperfluousY)) {
        if (object.collision(point.x, point.y)) {
            return true;
        }
    }
    return false;
}

bool Material::
staticAbscissaCollision(const Material::MaterialObject &object, const Material::MaterialObject &processed) noexcept {
    return staticAbscissaCollision(minCoordinates(object), maxCoordinates(object), object, processed);
}

bool Material::
staticOrdinateCollision(const Material::MaterialObject &object, const Material::MaterialObject &processed) noexcept {
    return staticOrdinateCollision(minCoordinates(object), maxCoordinates(object), object, processed);
}
