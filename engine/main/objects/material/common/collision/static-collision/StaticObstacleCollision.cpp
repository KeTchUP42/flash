//
// Created by roman on 20.09.2020.
//

#include "StaticObstacleCollision.h"
#include "../algorithms/CoordinatesCalculation.h"
#include "../algorithms/CollisionAlgorithms.h"

Obstacles::Obstacle *
Material::StaticObstacleCollision::abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle : unifier->getObstacles()) {

        if (obstacle.get() == object) continue;

        if (staticAbscissaMoveAble(objectMinCoordinates, objectMaxCoordinates, *object, *obstacle.get())) {
            return obstacle.get();
        }
    }
    return nullptr;
}

Obstacles::Obstacle *
Material::StaticObstacleCollision::ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle : unifier->getObstacles()) {

        if (obstacle.get() == object) continue;

        if (staticOrdinateMoveAble(objectMinCoordinates, objectMaxCoordinates, *object, *obstacle.get()))
            return obstacle.get();
    }
    return nullptr;
}
