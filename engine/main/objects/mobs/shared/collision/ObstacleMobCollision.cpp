//
// Created by roman on 12.09.2020.
//

#include "ObstacleMobCollision.h"

#define _USE_MATH_DEFINES

#include <math.h>

Mobs::ObstacleMobCollision::ObstacleMobCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY)
        : CollisionStrategy(unifier), ANALYSIS_STEP_X(analysisStepX), ANALYSIS_STEP_Y(analysisStepY) {}

Components::Point Mobs::maxCoordinates(const Possibilities::RectangleGetters &rectangle) {
    const float rectangleAngleInRadians = rectangle.getRotation() * M_PI / 180;
    const float sinAngle = std::sin(rectangleAngleInRadians);
    const float cosAngle = std::cos(rectangleAngleInRadians);

    const float rectangleXStart = rectangle.getPosition().x;

    float rectangleX2 = -sinAngle + cosAngle * rectangle.getSize().width + rectangleXStart;
    float rectangleX3 = -sinAngle * rectangle.getSize().height + cosAngle * rectangle.getSize().width + rectangleXStart;
    float rectangleX4 = -sinAngle * rectangle.getSize().height + cosAngle + rectangleXStart;

    const float rectangleYStart = rectangle.getPosition().y;

    float rectangleY2 = cosAngle + sinAngle * rectangle.getSize().width + rectangleYStart;
    float rectangleY3 = cosAngle * rectangle.getSize().height + sinAngle * rectangle.getSize().width + rectangleYStart;
    float rectangleY4 = cosAngle * rectangle.getSize().height + sinAngle + rectangleYStart;

    return Components::Point(std::max(std::max(rectangleX2, rectangleX3), std::max(rectangleX4, rectangleXStart)),
                             std::max(std::max(rectangleY2, rectangleY3), std::max(rectangleY4, rectangleYStart)));
}

Components::Point Mobs::minCoordinates(const Possibilities::RectangleGetters &rectangle) {
    const float rectangleAngleInRadians = rectangle.getRotation() * M_PI / 180;
    const float sinAngle = std::sin(rectangleAngleInRadians);
    const float cosAngle = std::cos(rectangleAngleInRadians);

    const float rectangleXStart = rectangle.getPosition().x;

    float rectangleX2 = -sinAngle + cosAngle * rectangle.getSize().width + rectangleXStart;
    float rectangleX3 = -sinAngle * rectangle.getSize().height + cosAngle * rectangle.getSize().width + rectangleXStart;
    float rectangleX4 = -sinAngle * rectangle.getSize().height + cosAngle + rectangleXStart;

    const float rectangleYStart = rectangle.getPosition().y;

    float rectangleY2 = cosAngle + sinAngle * rectangle.getSize().width + rectangleYStart;
    float rectangleY3 = cosAngle * rectangle.getSize().height + sinAngle * rectangle.getSize().width + rectangleYStart;
    float rectangleY4 = cosAngle * rectangle.getSize().height + sinAngle + rectangleYStart;

    return Components::Point(std::min(std::min(rectangleX2, rectangleX3), std::min(rectangleX4, rectangleXStart)),
                             std::min(std::min(rectangleY2, rectangleY3), std::min(rectangleY4, rectangleYStart)));
}

Obstacles::Obstacle *Mobs::ObstacleMobCollision::abscissaMoveAble(Mobs::Mob *mob) const noexcept {
    if (mob->getMoveSpeed().xSpeed == 0) return nullptr;

    Components::Point mobMinCoordinates = minCoordinates(*mob);
    Components::Point mobMaxCoordinates = maxCoordinates(*mob);

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle : _unifier->getObstacles()) {

        Components::Point obstacleMinCoordinates = minCoordinates(*obstacle);
        Components::Point obstacleMaxCoordinates = maxCoordinates(*obstacle);

        if (!((((mobMinCoordinates.y >= obstacleMinCoordinates.y) && (mobMinCoordinates.y <= obstacleMaxCoordinates.y)) ||
               ((mobMaxCoordinates.y >= obstacleMinCoordinates.y) && (mobMaxCoordinates.y <= obstacleMaxCoordinates.y))) ||
              (((obstacleMinCoordinates.y >= mobMinCoordinates.y) && (obstacleMinCoordinates.y <= mobMaxCoordinates.y)) ||
               ((obstacleMaxCoordinates.y >= mobMinCoordinates.y) && (obstacleMaxCoordinates.y <= mobMaxCoordinates.y)))))
            continue; //Takes only obstacle with valid position.

        const float mobMoveXSpeed = mob->getMoveSpeed().xSpeed;

        if ((mobMoveXSpeed > 0) && (mobMaxCoordinates.x > obstacleMaxCoordinates.x)) continue;
        if ((mobMoveXSpeed < 0) && (mobMinCoordinates.x < obstacleMinCoordinates.x)) continue;

        if ((mobMoveXSpeed > 0) && (mobMaxCoordinates.x + mobMoveXSpeed < obstacleMinCoordinates.x)) continue;
        if ((mobMoveXSpeed < 0) && (mobMinCoordinates.x + mobMoveXSpeed > obstacleMaxCoordinates.x)) continue;

        for (float y = mobMinCoordinates.y + ANALYSIS_STEP_Y; y < mobMaxCoordinates.y; y += ANALYSIS_STEP_Y) {

            if (obstacle->collision((mobMoveXSpeed > 0 ? mobMaxCoordinates.x : mobMinCoordinates.x) + mobMoveXSpeed, y)) {
                return obstacle.get();
            }
        }
    }
    return nullptr;
}

Obstacles::Obstacle *Mobs::ObstacleMobCollision::ordinateMoveAble(Mobs::Mob *mob) const noexcept {
    if (mob->getMoveSpeed().ySpeed == 0) return nullptr;

    Components::Point mobMinCoordinates = minCoordinates(*mob);
    Components::Point mobMaxCoordinates = maxCoordinates(*mob);

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle : _unifier->getObstacles()) {

        Components::Point obstacleMinCoordinates = minCoordinates(*obstacle);
        Components::Point obstacleMaxCoordinates = maxCoordinates(*obstacle);

        if (!((((mobMinCoordinates.x >= obstacleMinCoordinates.x) && (mobMinCoordinates.x <= obstacleMaxCoordinates.x)) ||
               ((mobMaxCoordinates.x >= obstacleMinCoordinates.x) && (mobMaxCoordinates.x <= obstacleMaxCoordinates.x))) ||
              (((obstacleMinCoordinates.x >= mobMinCoordinates.x) && (obstacleMinCoordinates.x <= mobMaxCoordinates.x)) ||
               ((obstacleMaxCoordinates.x >= mobMinCoordinates.x) && (obstacleMaxCoordinates.x <= mobMaxCoordinates.x)))))
            continue; //Takes only obstacle with valid position.

        const float mobMoveYSpeed = mob->getMoveSpeed().ySpeed;

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

void Mobs::ObstacleMobCollision::setAnalysisStepX(float analysisStepX) noexcept {
    ObstacleMobCollision::ANALYSIS_STEP_X = analysisStepX;
}

void Mobs::ObstacleMobCollision::setAnalysisStepY(float analysisStepY) noexcept {
    ObstacleMobCollision::ANALYSIS_STEP_Y = analysisStepY;
}
