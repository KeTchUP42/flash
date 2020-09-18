//
// Created by roman on 12.09.2020.
//

#include "ObstacleCollision.h"
#include "coordinates/CoordinatesCalculation.h"

Material::ObstacleCollision::ObstacleCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY)
        : CollisionStrategy(unifier), ANALYSIS_STEP_X(analysisStepX), ANALYSIS_STEP_Y(analysisStepY) {}

Obstacles::Obstacle *Material::ObstacleCollision::abscissaMoveAble(Material::MaterialObject *object) const noexcept {
    if (object->getMoveSpeed().xSpeed == 0) return nullptr;

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

        const float objectMoveXSpeed = object->getMoveSpeed().xSpeed;

        if ((objectMoveXSpeed > 0) && (objectMaxCoordinates.x > obstacleMaxCoordinates.x)) continue;
        if ((objectMoveXSpeed < 0) && (objectMinCoordinates.x < obstacleMinCoordinates.x)) continue;

        if ((objectMoveXSpeed > 0) && (objectMaxCoordinates.x + objectMoveXSpeed < obstacleMinCoordinates.x)) continue;
        if ((objectMoveXSpeed < 0) && (objectMinCoordinates.x + objectMoveXSpeed > obstacleMaxCoordinates.x)) continue;

        for (float y = objectMinCoordinates.y + ANALYSIS_STEP_Y; y < objectMaxCoordinates.y; y += ANALYSIS_STEP_Y) {

            if (obstacle->collision((objectMoveXSpeed > 0 ? objectMaxCoordinates.x : objectMinCoordinates.x) + objectMoveXSpeed,
                                    y)) {
                return obstacle.get();
            }
        }
    }
    return nullptr;
}

Obstacles::Obstacle *Material::ObstacleCollision::ordinateMoveAble(Material::MaterialObject *object) const noexcept {
    if (object->getMoveSpeed().ySpeed == 0) return nullptr;

    Components::Point mobMinCoordinates = minCoordinates(*object);
    Components::Point mobMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle : _unifier->getObstacles()) {

        if (obstacle.get() == object) continue;

        Components::Point obstacleMinCoordinates = minCoordinates(*obstacle);
        Components::Point obstacleMaxCoordinates = maxCoordinates(*obstacle);

        if (!((((mobMinCoordinates.x >= obstacleMinCoordinates.x) && (mobMinCoordinates.x <= obstacleMaxCoordinates.x)) ||
               ((mobMaxCoordinates.x >= obstacleMinCoordinates.x) && (mobMaxCoordinates.x <= obstacleMaxCoordinates.x))) ||
              (((obstacleMinCoordinates.x >= mobMinCoordinates.x) && (obstacleMinCoordinates.x <= mobMaxCoordinates.x)) ||
               ((obstacleMaxCoordinates.x >= mobMinCoordinates.x) && (obstacleMaxCoordinates.x <= mobMaxCoordinates.x)))))
            continue; //Takes only obstacle with valid position.

        const float mobMoveYSpeed = object->getMoveSpeed().ySpeed;

        if ((mobMoveYSpeed > 0) && (mobMaxCoordinates.y > obstacleMaxCoordinates.y)) continue;
        if ((mobMoveYSpeed < 0) && (mobMinCoordinates.y < obstacleMinCoordinates.y)) continue;

        if ((mobMoveYSpeed > 0) && (mobMaxCoordinates.y + mobMoveYSpeed < obstacleMinCoordinates.y)) continue;
        if ((mobMoveYSpeed < 0) && (mobMinCoordinates.y + mobMoveYSpeed > obstacleMaxCoordinates.y)) continue;

        for (float x = mobMinCoordinates.x + ANALYSIS_STEP_X; x < mobMaxCoordinates.x; x += ANALYSIS_STEP_X) {

            if (obstacle->collision(x, (mobMoveYSpeed > 0 ? mobMaxCoordinates.y : mobMinCoordinates.y) + mobMoveYSpeed)) {
                return obstacle.get();
            }
        }
    }
    return nullptr;
}

void Material::ObstacleCollision::setAnalysisStepX(float analysisStepX) noexcept {
    ObstacleCollision::ANALYSIS_STEP_X = analysisStepX;
}

void Material::ObstacleCollision::setAnalysisStepY(float analysisStepY) noexcept {
    ObstacleCollision::ANALYSIS_STEP_Y = analysisStepY;
}
