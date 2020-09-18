//
// Created by roman on 18.09.2020.
//

#include "MobCollision.h"
#include "coordinates/CoordinatesCalculation.h"

Material::MobCollision::MobCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY)
        : CollisionStrategy(unifier), ANALYSIS_STEP_X(analysisStepX), ANALYSIS_STEP_Y(analysisStepY) {}


Material::MaterialObject *Material::MobCollision::abscissaMoveAble(Material::MaterialObject *object) const noexcept {
    if (object->getMoveSpeed().xSpeed == 0) return nullptr;

    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    const float objectMoveXSpeed = object->getMoveSpeed().xSpeed;

    for (const std::shared_ptr<Mobs::Monster> &monster : _unifier->getMonsters()) {

        if (monster.get() == object) continue;

        Components::Point monsterMinCoordinates = minCoordinates(*monster);
        Components::Point monsterMaxCoordinates = maxCoordinates(*monster);

        if (!((((objectMinCoordinates.y >= monsterMinCoordinates.y) && (objectMinCoordinates.y <= monsterMaxCoordinates.y)) ||
               ((objectMaxCoordinates.y >= monsterMinCoordinates.y) && (objectMaxCoordinates.y <= monsterMaxCoordinates.y))) ||
              (((monsterMinCoordinates.y >= objectMinCoordinates.y) && (monsterMinCoordinates.y <= objectMaxCoordinates.y)) ||
               ((monsterMaxCoordinates.y >= objectMinCoordinates.y) && (monsterMaxCoordinates.y <= objectMaxCoordinates.y)))))
            continue; //Takes only monster with valid position.

        if ((objectMoveXSpeed > 0) && (objectMaxCoordinates.x > monsterMaxCoordinates.x)) continue;
        if ((objectMoveXSpeed < 0) && (objectMinCoordinates.x < monsterMinCoordinates.x)) continue;

        if ((objectMoveXSpeed > 0) && (objectMaxCoordinates.x + objectMoveXSpeed < monsterMinCoordinates.x)) continue;
        if ((objectMoveXSpeed < 0) && (objectMinCoordinates.x + objectMoveXSpeed > monsterMaxCoordinates.x)) continue;

        for (float y = objectMinCoordinates.y + ANALYSIS_STEP_Y; y < objectMaxCoordinates.y; y += ANALYSIS_STEP_Y) {

            if (monster->collision((objectMoveXSpeed > 0 ? objectMaxCoordinates.x : objectMinCoordinates.x) + objectMoveXSpeed, y)) {
                return monster.get();
            }
        }
    }

    for (const std::shared_ptr<Mobs::Player> &player : _unifier->getPlayers()) {

        if (player.get() == object) continue;

        Components::Point playerMinCoordinates = minCoordinates(*player);
        Components::Point playerMaxCoordinates = maxCoordinates(*player);

        if (!((((objectMinCoordinates.y >= playerMinCoordinates.y) && (objectMinCoordinates.y <= playerMaxCoordinates.y)) ||
               ((objectMaxCoordinates.y >= playerMinCoordinates.y) && (objectMaxCoordinates.y <= playerMaxCoordinates.y))) ||
              (((playerMinCoordinates.y >= objectMinCoordinates.y) && (playerMinCoordinates.y <= objectMaxCoordinates.y)) ||
               ((playerMaxCoordinates.y >= objectMinCoordinates.y) && (playerMaxCoordinates.y <= objectMaxCoordinates.y)))))
            continue; //Takes only player with valid position.

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

Material::MaterialObject *Material::MobCollision::ordinateMoveAble(Material::MaterialObject *object) const noexcept {
    if (object->getMoveSpeed().ySpeed == 0) return nullptr;

    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    const float objectMoveYSpeed = object->getMoveSpeed().ySpeed;

    for (const std::shared_ptr<Mobs::Monster> &monster : _unifier->getMonsters()) {

        if (monster.get() == object) continue;

        Components::Point monsterMinCoordinates = minCoordinates(*monster);
        Components::Point monsterMaxCoordinates = maxCoordinates(*monster);

        if (!((((objectMinCoordinates.x >= monsterMinCoordinates.x) && (objectMinCoordinates.x <= monsterMaxCoordinates.x)) ||
               ((objectMaxCoordinates.x >= monsterMinCoordinates.x) && (objectMaxCoordinates.x <= monsterMaxCoordinates.x))) ||
              (((monsterMinCoordinates.x >= objectMinCoordinates.x) && (monsterMinCoordinates.x <= objectMaxCoordinates.x)) ||
               ((monsterMaxCoordinates.x >= objectMinCoordinates.x) && (monsterMaxCoordinates.x <= objectMaxCoordinates.x)))))
            continue; //Takes only monster with valid position.

        if ((objectMoveYSpeed > 0) && (objectMaxCoordinates.y > monsterMaxCoordinates.y)) continue;
        if ((objectMoveYSpeed < 0) && (objectMinCoordinates.y < monsterMinCoordinates.y)) continue;

        if ((objectMoveYSpeed > 0) && (objectMaxCoordinates.y + objectMoveYSpeed < monsterMinCoordinates.y)) continue;
        if ((objectMoveYSpeed < 0) && (objectMinCoordinates.y + objectMoveYSpeed > monsterMaxCoordinates.y)) continue;

        for (float x = objectMinCoordinates.x + ANALYSIS_STEP_X; x < objectMaxCoordinates.x; x += ANALYSIS_STEP_X) {

            if (monster->collision(x, (objectMoveYSpeed > 0 ? objectMaxCoordinates.y : objectMinCoordinates.y) + objectMoveYSpeed)) {
                return monster.get();
            }
        }
    }

    for (const std::shared_ptr<Mobs::Player> &player : _unifier->getPlayers()) {

        if (player.get() == object) continue;

        Components::Point playerMinCoordinates = minCoordinates(*player);
        Components::Point playerMaxCoordinates = maxCoordinates(*player);

        if (!((((objectMinCoordinates.x >= playerMinCoordinates.x) && (objectMinCoordinates.x <= playerMaxCoordinates.x)) ||
               ((objectMaxCoordinates.x >= playerMinCoordinates.x) && (objectMaxCoordinates.x <= playerMaxCoordinates.x))) ||
              (((playerMinCoordinates.x >= objectMinCoordinates.x) && (playerMinCoordinates.x <= objectMaxCoordinates.x)) ||
               ((playerMaxCoordinates.x >= objectMinCoordinates.x) && (playerMaxCoordinates.x <= objectMaxCoordinates.x)))))
            continue; //Takes only player with valid position.

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

void Material::MobCollision::setAnalysisStepX(float analysisStepX) noexcept {
    MobCollision::ANALYSIS_STEP_X = analysisStepX;
}

void Material::MobCollision::setAnalysisStepY(float analysisStepY) noexcept {
    MobCollision::ANALYSIS_STEP_Y = analysisStepY;
}
