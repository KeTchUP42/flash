//
// Created by roman on 20.09.2020.
//

#include "StaticObstacleCollision.h"
#include "../coordinates/CoordinatesCalculation.h"
#include "additionally/ExtremeCoordinates.h"

Material::StaticObstacleCollision::StaticObstacleCollision(Unite::Unifier *unifier) : CollisionStrategy(unifier) {}

Obstacles::Obstacle *Material::StaticObstacleCollision::abscissaMoveAble(Material::MaterialObject *object) const noexcept {
    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle : _unifier->getObstacles()) {

        if (obstacle.get() == object) continue;

        Components::Point obstacleMinCoordinates = minCoordinates(*obstacle);
        Components::Point obstacleMaxCoordinates = maxCoordinates(*obstacle);

        if (!((((objectMinCoordinates.y >= obstacleMinCoordinates.y) && (objectMinCoordinates.y <= obstacleMaxCoordinates.y)) ||
               ((objectMaxCoordinates.y >= obstacleMinCoordinates.y) && (objectMaxCoordinates.y <= obstacleMaxCoordinates.y))) ||
              (((obstacleMinCoordinates.y >= objectMinCoordinates.y) && (obstacleMinCoordinates.y <= objectMaxCoordinates.y)) ||
               ((obstacleMaxCoordinates.y >= objectMinCoordinates.y) && (obstacleMaxCoordinates.y <= objectMaxCoordinates.y)))))
            continue; //Takes only obstacle with valid position.

        //Optimization.
        if (obstacleMaxCoordinates.x > objectMaxCoordinates.x) {
            if (obstacleMinCoordinates.x - objectMaxCoordinates.x > 0) continue;
        } else {
            if (objectMinCoordinates.x - obstacleMaxCoordinates.x > 0) continue;
        }

        float objectSuperfluousX = ((obstacleMaxCoordinates.x > objectMaxCoordinates.x)
                                    ? objectMinCoordinates.x : objectMaxCoordinates.x);

        for (const Components::Point &point : extremeCoordinatesAbscissa(*object, objectSuperfluousX)) {
            if (obstacle->collision(point.x, point.y)) {
                return obstacle.get();
            }
        }

        float obstacleSuperfluousX = ((obstacleMaxCoordinates.x > objectMaxCoordinates.x)
                                      ? obstacleMaxCoordinates.x : obstacleMinCoordinates.x);

        for (const Components::Point &point : extremeCoordinatesAbscissa(*obstacle, obstacleSuperfluousX)) {
            if (object->collision(point.x, point.y)) {
                return obstacle.get();
            }
        }
    }
    return nullptr;
}

Obstacles::Obstacle *Material::StaticObstacleCollision::ordinateMoveAble(Material::MaterialObject *object) const noexcept {
    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle : _unifier->getObstacles()) {

        if (obstacle.get() == object) continue;

        Components::Point obstacleMinCoordinates = minCoordinates(*obstacle);
        Components::Point obstacleMaxCoordinates = maxCoordinates(*obstacle);

        if (!((((objectMinCoordinates.x >= obstacleMinCoordinates.x) && (objectMinCoordinates.x <= obstacleMaxCoordinates.x)) ||
               ((objectMaxCoordinates.x >= obstacleMinCoordinates.x) && (objectMaxCoordinates.x <= obstacleMaxCoordinates.x))) ||
              (((obstacleMinCoordinates.x >= objectMinCoordinates.x) && (obstacleMinCoordinates.x <= objectMaxCoordinates.x)) ||
               ((obstacleMaxCoordinates.x >= objectMinCoordinates.x) && (obstacleMaxCoordinates.x <= objectMaxCoordinates.x)))))
            continue; //Takes only obstacle with valid position.

        //Optimization.
        if (obstacleMaxCoordinates.y > objectMaxCoordinates.y) {
            if (obstacleMinCoordinates.y - objectMaxCoordinates.y > 0) continue;
        } else {
            if (objectMinCoordinates.y - obstacleMaxCoordinates.y > 0) continue;
        }

        float objectSuperfluousY = ((obstacleMaxCoordinates.y > objectMaxCoordinates.y)
                                    ? objectMinCoordinates.y : objectMaxCoordinates.y);

        for (const Components::Point &point : extremeCoordinatesOrdinate(*object, objectSuperfluousY)) {
            if (obstacle->collision(point.x, point.y)) {
                return obstacle.get();
            }
        }

        float obstacleSuperfluousY = ((obstacleMaxCoordinates.y > objectMaxCoordinates.y)
                                      ? obstacleMaxCoordinates.y : obstacleMinCoordinates.y);

        for (const Components::Point &point : extremeCoordinatesOrdinate(*obstacle, obstacleSuperfluousY)) {
            if (object->collision(point.x, point.y)) {
                return obstacle.get();
            }
        }
    }
    return nullptr;
}
