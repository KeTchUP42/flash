//
// Created by roman on 12.09.2020.
//

#include "MovingObstacleCollision.h"
#include "../algorithms/CoordinatesCalculation.h"
#include "../algorithms/CollisionAlgorithms.h"

Material::MovingObstacleCollision::MovingObstacleCollision(float analysisStepX, float analysisStepY)
        : MovingCollision(analysisStepX, analysisStepY) {}

Obstacles::Obstacle *
Material::MovingObstacleCollision::abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    if (object->getMoveSpeed().xSpeed == 0) return nullptr;

    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle : unifier->getObstacles()) {

        if (obstacle.get() == object) continue;

        if (movingAbscissaCollision(objectMinCoordinates, objectMaxCoordinates, *object, *obstacle, ANALYSIS_STEP_Y)) {
            return obstacle.get();
        }
    }
    return nullptr;
}

Obstacles::Obstacle *
Material::MovingObstacleCollision::ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    if (object->getMoveSpeed().ySpeed == 0) return nullptr;

    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle : unifier->getObstacles()) {

        if (obstacle.get() == object) continue;

        if (movingOrdinateCollision(objectMinCoordinates, objectMaxCoordinates, *object, *obstacle, ANALYSIS_STEP_X)) {
            return obstacle.get();
        }
    }
    return nullptr;
}
