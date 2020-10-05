//
// Created by roman on 03.10.2020.
//

#include "CollisionAlgorithms.h"
#include "ExtremeCoordinates.h"
#include "CoordinatesCalculation.h"

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
movingAbscissaCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                        Material::MaterialObject &object, const Material::MaterialObject &processed, float yStep) noexcept {

    Components::Point processedMinCoordinates = minCoordinates(processed);
    Components::Point processedMaxCoordinates = maxCoordinates(processed);

    if (!((((objectMinCoordinates.y >= processedMinCoordinates.y) && (objectMinCoordinates.y <= processedMaxCoordinates.y)) ||
           ((objectMaxCoordinates.y >= processedMinCoordinates.y) && (objectMaxCoordinates.y <= processedMaxCoordinates.y))) ||
          (((processedMinCoordinates.y >= objectMinCoordinates.y) && (processedMinCoordinates.y <= objectMaxCoordinates.y)) ||
           ((processedMaxCoordinates.y >= objectMinCoordinates.y) && (processedMaxCoordinates.y <= objectMaxCoordinates.y)))))
        return false; //Takes only processed with valid position.

    const float objectMoveXSpeed = object.getMoveSpeed().xSpeed;

    if ((objectMoveXSpeed > 0) && (objectMaxCoordinates.x > processedMaxCoordinates.x)) return false;
    if ((objectMoveXSpeed < 0) && (objectMinCoordinates.x < processedMinCoordinates.x)) return false;

    if ((objectMoveXSpeed > 0) && (objectMaxCoordinates.x + objectMoveXSpeed < processedMinCoordinates.x)) return false;
    if ((objectMoveXSpeed < 0) && (objectMinCoordinates.x + objectMoveXSpeed > processedMaxCoordinates.x)) return false;

    for (float y = objectMinCoordinates.y + yStep; y < objectMaxCoordinates.y; y += yStep) {

        if (processed.collision((objectMoveXSpeed > 0 ? objectMaxCoordinates.x : objectMinCoordinates.x) + objectMoveXSpeed, y)) {

            int moveLength = static_cast<int>(objectMoveXSpeed / 2);
            int moved = 0;
            while (moveLength != 0) {
                if (processed.collision((moveLength > 0 ? objectMaxCoordinates.x : objectMinCoordinates.x) + moved + moveLength, y)) {
                    moveLength /= 2;
                    continue;
                }
                object.move(moveLength, 0);
                moved += moveLength;
                moveLength += moveLength < 0 ? 1 : -1;
            }
            return true;
        }
    }
    return false;
}

bool Material::
movingOrdinateCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                        Material::MaterialObject &object, const Material::MaterialObject &processed, float xStep) noexcept {

    Components::Point processedMinCoordinates = minCoordinates(processed);
    Components::Point processedMaxCoordinates = maxCoordinates(processed);

    if (!((((objectMinCoordinates.x >= processedMinCoordinates.x) && (objectMinCoordinates.x <= processedMaxCoordinates.x)) ||
           ((objectMaxCoordinates.x >= processedMinCoordinates.x) && (objectMaxCoordinates.x <= processedMaxCoordinates.x))) ||
          (((processedMinCoordinates.x >= objectMinCoordinates.x) && (processedMinCoordinates.x <= objectMaxCoordinates.x)) ||
           ((processedMaxCoordinates.x >= objectMinCoordinates.x) && (processedMaxCoordinates.x <= objectMaxCoordinates.x)))))
        return false; //Takes only processed with valid position.

    const float objectMoveYSpeed = object.getMoveSpeed().ySpeed;

    if ((objectMoveYSpeed > 0) && (objectMaxCoordinates.y > processedMaxCoordinates.y)) return false;
    if ((objectMoveYSpeed < 0) && (objectMinCoordinates.y < processedMinCoordinates.y)) return false;

    if ((objectMoveYSpeed > 0) && (objectMaxCoordinates.y + objectMoveYSpeed < processedMinCoordinates.y)) return false;
    if ((objectMoveYSpeed < 0) && (objectMinCoordinates.y + objectMoveYSpeed > processedMaxCoordinates.y)) return false;

    for (float x = objectMinCoordinates.x + xStep; x < objectMaxCoordinates.x; x += xStep) {

        if (processed.collision(x, (objectMoveYSpeed > 0 ? objectMaxCoordinates.y : objectMinCoordinates.y) + objectMoveYSpeed)) {

            int moveLength = static_cast<int>(objectMoveYSpeed / 2);
            int moved = 0;
            while (moveLength != 0) {
                if (processed.collision(x, (moveLength > 0 ? objectMaxCoordinates.y : objectMinCoordinates.y) + moved + moveLength)) {
                    moveLength /= 2;
                    continue;
                }
                object.move(0, moveLength);
                moved += moveLength;
                moveLength += moveLength < 0 ? 1 : -1;
            }
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

bool Material::
movingAbscissaCollision(Material::MaterialObject &object, const Material::MaterialObject &processed, float yStep) noexcept {
    return movingAbscissaCollision(minCoordinates(object), maxCoordinates(object), object, processed, yStep);
}

bool Material::
movingOrdinateCollision(Material::MaterialObject &object, const Material::MaterialObject &processed, float xStep) noexcept {
    return movingOrdinateCollision(minCoordinates(object), maxCoordinates(object), object, processed, xStep);
}


