//
// Created by roman on 19.09.2020.
//

#include "MovingMonsterCollision.h"
#include "../algorithms/CoordinatesCalculation.h"
#include "../algorithms/CollisionAlgorithms.h"

Material::MovingMonsterCollision::MovingMonsterCollision(float analysisStepX, float analysisStepY)
        : MovingCollision(analysisStepX, analysisStepY) {}

Mobs::Monster *
Material::MovingMonsterCollision::abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    if (object->getMoveSpeed().xSpeed == 0) return nullptr;

    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Monster> &monster : unifier->getMonsters()) {

        if (monster.get() == object) continue;

        if (movingAbscissaCollision(objectMinCoordinates, objectMaxCoordinates, *object, *monster, ANALYSIS_STEP_Y)) {
            return monster.get();
        }
    }
    return nullptr;
}

Mobs::Monster *
Material::MovingMonsterCollision::ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    if (object->getMoveSpeed().ySpeed == 0) return nullptr;

    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Monster> &monster : unifier->getMonsters()) {

        if (monster.get() == object) continue;

        if (movingOrdinateCollision(objectMinCoordinates, objectMaxCoordinates, *object, *monster, ANALYSIS_STEP_X)) {
            return monster.get();
        }
    }
    return nullptr;
}

