//
// Created by roman on 03.10.2020.
//

#include "MovingCollisionAlgorithms.h"
#include "../coordinates/CoordinatesCalculation.h"
#include "../coordinates/MovingCollisionFunctions.h"
#include <cmath>

bool Material::
movingAbscissaCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                        Material::MaterialObject &object, const Material::MaterialObject &processed, float step) noexcept {

    Components::Point processedMinCoordinates = minCoordinates(processed);
    Components::Point processedMaxCoordinates = maxCoordinates(processed);

    if (!((((objectMinCoordinates.y >= processedMinCoordinates.y) && (objectMinCoordinates.y <= processedMaxCoordinates.y)) ||
           ((objectMaxCoordinates.y >= processedMinCoordinates.y) && (objectMaxCoordinates.y <= processedMaxCoordinates.y))) ||
          (((processedMinCoordinates.y >= objectMinCoordinates.y) && (processedMinCoordinates.y <= objectMaxCoordinates.y)) ||
           ((processedMaxCoordinates.y >= objectMinCoordinates.y) && (processedMaxCoordinates.y <= objectMaxCoordinates.y)))))
        return false; //Takes only processed with valid position.

    const float objectMoveXSpeed = object.getSpeed().xSpeed;

    if ((objectMoveXSpeed > 0) && (objectMaxCoordinates.x > processedMaxCoordinates.x)) return false;
    if ((objectMoveXSpeed < 0) && (objectMinCoordinates.x < processedMinCoordinates.x)) return false;

    if ((objectMoveXSpeed > 0) && (objectMaxCoordinates.x + objectMoveXSpeed < processedMinCoordinates.x)) return false;
    if ((objectMoveXSpeed < 0) && (objectMinCoordinates.x + objectMoveXSpeed > processedMaxCoordinates.x)) return false;

    std::vector<Components::Point> pointsOffset = pickoutNodulesY(object, std::pair<float, float>(objectMinCoordinates.y,
                                                                                                  objectMaxCoordinates.y), (objectMoveXSpeed > 0));
    for (size_t i = 0; i < pointsOffset.size() - 1; ++i) {

        float xside = std::abs(pointsOffset[i].x - pointsOffset[i + 1].x);
        float yside = std::abs(pointsOffset[i].y - pointsOffset[i + 1].y);
        float diag = std::sqrt(xside * xside + yside * yside);

        short pointXSide = ((pointsOffset[i].x > pointsOffset[i + 1].x) ? -1 : 1);
        short pointYSide = ((pointsOffset[i].y > pointsOffset[i + 1].y) ? -1 : 1);

        for (float stp = (i == 0) ? 1 : 0; stp < diag; stp = (stp + step >= diag) ? diag : stp + step) {

            float x = pointXSide * ((stp * xside) / diag) + pointsOffset[i].x;
            float y = pointYSide * ((stp * yside) / diag) + pointsOffset[i].y;

            if (processed.collision(x + objectMoveXSpeed, y)) {

                int length = static_cast<int>(objectMoveXSpeed / 2);
                int distance = 0;
                while (length != 0) {
                    if (processed.collision((length > 0 ? objectMaxCoordinates.x : objectMinCoordinates.x) + distance + length, y)) {
                        length /= 2;
                        continue;
                    }
                    object.move(length, 0);
                    distance += length;
                    length += length < 0 ? 1 : -1;
                }
                return true;
            }
        }
    }
    return false;
}

bool Material::
movingOrdinateCollision(const Components::Point &objectMinCoordinates, const Components::Point &objectMaxCoordinates,
                        Material::MaterialObject &object, const Material::MaterialObject &processed, float step) noexcept {

    Components::Point processedMinCoordinates = minCoordinates(processed);
    Components::Point processedMaxCoordinates = maxCoordinates(processed);

    if (!((((objectMinCoordinates.x >= processedMinCoordinates.x) && (objectMinCoordinates.x <= processedMaxCoordinates.x)) ||
           ((objectMaxCoordinates.x >= processedMinCoordinates.x) && (objectMaxCoordinates.x <= processedMaxCoordinates.x))) ||
          (((processedMinCoordinates.x >= objectMinCoordinates.x) && (processedMinCoordinates.x <= objectMaxCoordinates.x)) ||
           ((processedMaxCoordinates.x >= objectMinCoordinates.x) && (processedMaxCoordinates.x <= objectMaxCoordinates.x)))))
        return false; //Takes only processed with valid position.

    const float objectMoveYSpeed = object.getSpeed().ySpeed;

    if ((objectMoveYSpeed > 0) && (objectMaxCoordinates.y > processedMaxCoordinates.y)) return false;
    if ((objectMoveYSpeed < 0) && (objectMinCoordinates.y < processedMinCoordinates.y)) return false;

    if ((objectMoveYSpeed > 0) && (objectMaxCoordinates.y + objectMoveYSpeed < processedMinCoordinates.y)) return false;
    if ((objectMoveYSpeed < 0) && (objectMinCoordinates.y + objectMoveYSpeed > processedMaxCoordinates.y)) return false;

    std::vector<Components::Point> pointsOffset = pickoutNodulesX(object, std::pair<float, float>(objectMinCoordinates.x,
                                                                                                  objectMaxCoordinates.x), (objectMoveYSpeed > 0));
    for (size_t i = 0; i < pointsOffset.size() - 1; ++i) {

        float xside = std::abs(pointsOffset[i].x - pointsOffset[i + 1].x);
        float yside = std::abs(pointsOffset[i].y - pointsOffset[i + 1].y);
        float diag = std::sqrt(xside * xside + yside * yside);

        short pointXSide = ((pointsOffset[i].x > pointsOffset[i + 1].x) ? -1 : 1);
        short pointYSide = ((pointsOffset[i].y > pointsOffset[i + 1].y) ? -1 : 1);

        for (float stp = (i == 0) ? 1 : 0; stp < diag; stp = (stp + step >= diag) ? diag : stp + step) {

            float x = pointXSide * ((stp * xside) / diag) + pointsOffset[i].x;
            float y = pointYSide * ((stp * yside) / diag) + pointsOffset[i].y;

            if (processed.collision(x, y + objectMoveYSpeed)) {

                int length = static_cast<int>(objectMoveYSpeed / 2);
                int distance = 0;
                while (length != 0) {
                    if (processed.collision(x, (length > 0 ? objectMaxCoordinates.y : objectMinCoordinates.y) + distance + length)) {
                        length /= 2;
                        continue;
                    }
                    object.move(0, length);
                    distance += length;
                    length += length < 0 ? 1 : -1;
                }
                return true;
            }
        }
    }
    return false;
}

bool Material::
movingAbscissaCollision(Material::MaterialObject &object, const Material::MaterialObject &processed, float step) noexcept {
    return movingAbscissaCollision(minCoordinates(object), maxCoordinates(object), object, processed, step);
}

bool Material::
movingOrdinateCollision(Material::MaterialObject &object, const Material::MaterialObject &processed, float step) noexcept {
    return movingOrdinateCollision(minCoordinates(object), maxCoordinates(object), object, processed, step);
}


