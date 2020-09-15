//
// Created by roman on 12.09.2020.
//

#include "BasicMobCollision.h"

#define _USE_MATH_DEFINES

#include <math.h>

Mobs::BasicMobCollision::BasicMobCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY)
        : ANALYSIS_STEP_X(analysisStepX), ANALYSIS_STEP_Y(analysisStepY), CollisionStrategy(unifier) {}

Components::Point Mobs::maxCoordinates(const Possibilities::RectangleGetters &rectangle) {
    const float rectangleAngleInRadians = rectangle.getRotation() * M_PI / 180;
    const float rectangleXStart = rectangle.getPosition().x;

    float rectangleX2 = -std::sin(rectangleAngleInRadians) +
                        std::cos(rectangleAngleInRadians) * rectangle.getSize().width + rectangleXStart;
    float rectangleX3 = -std::sin(rectangleAngleInRadians) * rectangle.getSize().height +
                        std::cos(rectangleAngleInRadians) * rectangle.getSize().width + rectangleXStart;
    float rectangleX4 = -std::sin(rectangleAngleInRadians) * rectangle.getSize().height +
                        std::cos(rectangleAngleInRadians) + rectangleXStart;

    const float rectangleYStart = rectangle.getPosition().y;

    float rectangleY2 = std::cos(rectangleAngleInRadians) +
                        std::sin(rectangleAngleInRadians) * rectangle.getSize().width + rectangleYStart;
    float rectangleY3 = std::cos(rectangleAngleInRadians) * rectangle.getSize().height +
                        std::sin(rectangleAngleInRadians) * rectangle.getSize().width + rectangleYStart;
    float rectangleY4 = std::cos(rectangleAngleInRadians) * rectangle.getSize().height +
                        std::sin(rectangleAngleInRadians) + rectangleYStart;

    return Components::Point(std::max(std::max(rectangleX2, rectangleX3), std::max(rectangleX4, rectangleXStart)),
                             std::max(std::max(rectangleY2, rectangleY3), std::max(rectangleY4, rectangleYStart)));
}

Components::Point Mobs::minCoordinates(const Possibilities::RectangleGetters &rectangle) {
    const float rectangleAngleInRadians = rectangle.getRotation() * M_PI / 180;
    const float rectangleXStart = rectangle.getPosition().x;

    float rectangleX2 = -std::sin(rectangleAngleInRadians) +
                        std::cos(rectangleAngleInRadians) * rectangle.getSize().width + rectangleXStart;
    float rectangleX3 = -std::sin(rectangleAngleInRadians) * rectangle.getSize().height +
                        std::cos(rectangleAngleInRadians) * rectangle.getSize().width + rectangleXStart;
    float rectangleX4 = -std::sin(rectangleAngleInRadians) * rectangle.getSize().height +
                        std::cos(rectangleAngleInRadians) + rectangleXStart;

    const float rectangleYStart = rectangle.getPosition().y;

    float rectangleY2 = std::cos(rectangleAngleInRadians) +
                        std::sin(rectangleAngleInRadians) * rectangle.getSize().width + rectangleYStart;
    float rectangleY3 = std::cos(rectangleAngleInRadians) * rectangle.getSize().height +
                        std::sin(rectangleAngleInRadians) * rectangle.getSize().width + rectangleYStart;
    float rectangleY4 = std::cos(rectangleAngleInRadians) * rectangle.getSize().height +
                        std::sin(rectangleAngleInRadians) + rectangleYStart;

    return Components::Point(std::min(std::min(rectangleX2, rectangleX3), std::min(rectangleX4, rectangleXStart)),
                             std::min(std::min(rectangleY2, rectangleY3), std::min(rectangleY4, rectangleYStart)));
}

std::shared_ptr<Obstacles::Obstacle> Mobs::BasicMobCollision::abscissaMoveAble(Mobs::Mob *mob) const noexcept {
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

        for (float y = mobMinCoordinates.y + ANALYSIS_STEP_Y; y < mobMaxCoordinates.y; y += ANALYSIS_STEP_Y) {

            if (obstacle->collision((mob->getMoveSpeed().xSpeed > 0 ? mobMaxCoordinates.x : mobMinCoordinates.x)
                                    + mob->getMoveSpeed().xSpeed, y)) {
                return obstacle;
            }
        }
    }
    return nullptr;
}

std::shared_ptr<Obstacles::Obstacle> Mobs::BasicMobCollision::ordinateMoveAble(Mobs::Mob *mob) const noexcept {
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

        for (float x = mobMinCoordinates.x + ANALYSIS_STEP_X; x < mobMaxCoordinates.x; x += ANALYSIS_STEP_X) {

            if (obstacle->collision(x, (mob->getMoveSpeed().ySpeed > 0 ? mobMaxCoordinates.y : mobMinCoordinates.y)
                                       + mob->getMoveSpeed().ySpeed)) {
                return obstacle;
            }
        }
    }
    return nullptr;
}

void Mobs::BasicMobCollision::setAnalysisStepX(float analysisStepX) noexcept {
    BasicMobCollision::ANALYSIS_STEP_X = analysisStepX;
}

void Mobs::BasicMobCollision::setAnalysisStepY(float analysisStepY) noexcept {
    BasicMobCollision::ANALYSIS_STEP_Y = analysisStepY;
}
