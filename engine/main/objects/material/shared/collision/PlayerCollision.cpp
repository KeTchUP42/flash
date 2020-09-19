//
// Created by roman on 19.09.2020.
//

#include "PlayerCollision.h"
#include "coordinates/CoordinatesCalculation.h"

Material::PlayerCollision::PlayerCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY)
        : CollisionStrategy(unifier), ANALYSIS_STEP_X(analysisStepX), ANALYSIS_STEP_Y(analysisStepY) {}

Mobs::Player *Material::PlayerCollision::abscissaMoveAble(Material::MaterialObject *object) const noexcept {
    if (object->getMoveSpeed().xSpeed == 0) return nullptr;

    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Player> &player : _unifier->getPlayers()) {

        if (player.get() == object) continue;

        Components::Point playerMinCoordinates = minCoordinates(*player);
        Components::Point playerMaxCoordinates = maxCoordinates(*player);

        if (!((((objectMinCoordinates.y >= playerMinCoordinates.y) && (objectMinCoordinates.y <= playerMaxCoordinates.y)) ||
               ((objectMaxCoordinates.y >= playerMinCoordinates.y) && (objectMaxCoordinates.y <= playerMaxCoordinates.y))) ||
              (((playerMinCoordinates.y >= objectMinCoordinates.y) && (playerMinCoordinates.y <= objectMaxCoordinates.y)) ||
               ((playerMaxCoordinates.y >= objectMinCoordinates.y) && (playerMaxCoordinates.y <= objectMaxCoordinates.y)))))
            continue; //Takes only player with valid position.

        const float objectMoveXSpeed = object->getMoveSpeed().xSpeed;

        if ((objectMoveXSpeed > 0) && (objectMaxCoordinates.x > playerMaxCoordinates.x)) continue;
        if ((objectMoveXSpeed < 0) && (objectMinCoordinates.x < playerMinCoordinates.x)) continue;

        if ((objectMoveXSpeed > 0) && (objectMaxCoordinates.x + objectMoveXSpeed < playerMinCoordinates.x)) continue;
        if ((objectMoveXSpeed < 0) && (objectMinCoordinates.x + objectMoveXSpeed > playerMaxCoordinates.x)) continue;

        for (float y = objectMinCoordinates.y + ANALYSIS_STEP_Y; y < objectMaxCoordinates.y; y += ANALYSIS_STEP_Y) {

            if (player->collision((objectMoveXSpeed > 0 ? objectMaxCoordinates.x : objectMinCoordinates.x) + objectMoveXSpeed, y)) {
                return player.get();
            }
        }
    }
    return nullptr;
}

Mobs::Player *Material::PlayerCollision::ordinateMoveAble(Material::MaterialObject *object) const noexcept {
    if (object->getMoveSpeed().ySpeed == 0) return nullptr;

    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Player> &player : _unifier->getPlayers()) {

        if (player.get() == object) continue;

        Components::Point playerMinCoordinates = minCoordinates(*player);
        Components::Point playerMaxCoordinates = maxCoordinates(*player);

        if (!((((objectMinCoordinates.x >= playerMinCoordinates.x) && (objectMinCoordinates.x <= playerMaxCoordinates.x)) ||
               ((objectMaxCoordinates.x >= playerMinCoordinates.x) && (objectMaxCoordinates.x <= playerMaxCoordinates.x))) ||
              (((playerMinCoordinates.x >= objectMinCoordinates.x) && (playerMinCoordinates.x <= objectMaxCoordinates.x)) ||
               ((playerMaxCoordinates.x >= objectMinCoordinates.x) && (playerMaxCoordinates.x <= objectMaxCoordinates.x)))))
            continue; //Takes only player with valid position.

        const float objectMoveYSpeed = object->getMoveSpeed().ySpeed;

        if ((objectMoveYSpeed > 0) && (objectMaxCoordinates.y > playerMaxCoordinates.y)) continue;
        if ((objectMoveYSpeed < 0) && (objectMinCoordinates.y < playerMinCoordinates.y)) continue;

        if ((objectMoveYSpeed > 0) && (objectMaxCoordinates.y + objectMoveYSpeed < playerMinCoordinates.y)) continue;
        if ((objectMoveYSpeed < 0) && (objectMinCoordinates.y + objectMoveYSpeed > playerMaxCoordinates.y)) continue;

        for (float x = objectMinCoordinates.x + ANALYSIS_STEP_X; x < objectMaxCoordinates.x; x += ANALYSIS_STEP_X) {

            if (player->collision(x, (objectMoveYSpeed > 0 ? objectMaxCoordinates.y : objectMinCoordinates.y) + objectMoveYSpeed)) {
                return player.get();
            }
        }
    }
    return nullptr;
}

void Material::PlayerCollision::setAnalysisStepX(float analysisStepX) noexcept {
    PlayerCollision::ANALYSIS_STEP_X = analysisStepX;
}

void Material::PlayerCollision::setAnalysisStepY(float analysisStepY) noexcept {
    PlayerCollision::ANALYSIS_STEP_Y = analysisStepY;
}
