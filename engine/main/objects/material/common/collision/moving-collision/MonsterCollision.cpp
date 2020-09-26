//
// Created by roman on 19.09.2020.
//

#include "MonsterCollision.h"
#include "../coordinates/CoordinatesCalculation.h"

Material::MonsterCollision::MonsterCollision(float analysisStepX, float analysisStepY)
        : MovingCollision(analysisStepX, analysisStepY) {}

Mobs::Monster *Material::MonsterCollision::abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    if (object->getMoveSpeed().xSpeed == 0) return nullptr;

    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Monster> &monster : unifier->getMonsters()) {

        if (monster.get() == object) continue;

        Components::Point monsterMinCoordinates = minCoordinates(*monster);
        Components::Point monsterMaxCoordinates = maxCoordinates(*monster);

        if (!((((objectMinCoordinates.y >= monsterMinCoordinates.y) && (objectMinCoordinates.y <= monsterMaxCoordinates.y)) ||
               ((objectMaxCoordinates.y >= monsterMinCoordinates.y) && (objectMaxCoordinates.y <= monsterMaxCoordinates.y))) ||
              (((monsterMinCoordinates.y >= objectMinCoordinates.y) && (monsterMinCoordinates.y <= objectMaxCoordinates.y)) ||
               ((monsterMaxCoordinates.y >= objectMinCoordinates.y) && (monsterMaxCoordinates.y <= objectMaxCoordinates.y)))))
            continue; //Takes only monster with valid position.

        const float objectMoveXSpeed = object->getMoveSpeed().xSpeed;

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
    return nullptr;
}

Mobs::Monster *Material::MonsterCollision::ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    if (object->getMoveSpeed().ySpeed == 0) return nullptr;

    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Monster> &monster : unifier->getMonsters()) {

        if (monster.get() == object) continue;

        Components::Point monsterMinCoordinates = minCoordinates(*monster);
        Components::Point monsterMaxCoordinates = maxCoordinates(*monster);

        if (!((((objectMinCoordinates.x >= monsterMinCoordinates.x) && (objectMinCoordinates.x <= monsterMaxCoordinates.x)) ||
               ((objectMaxCoordinates.x >= monsterMinCoordinates.x) && (objectMaxCoordinates.x <= monsterMaxCoordinates.x))) ||
              (((monsterMinCoordinates.x >= objectMinCoordinates.x) && (monsterMinCoordinates.x <= objectMaxCoordinates.x)) ||
               ((monsterMaxCoordinates.x >= objectMinCoordinates.x) && (monsterMaxCoordinates.x <= objectMaxCoordinates.x)))))
            continue; //Takes only monster with valid position.

        const float objectMoveYSpeed = object->getMoveSpeed().ySpeed;

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
    return nullptr;
}

