//
// Created by roman on 19.09.2020.
//

#include "MovingPlayerCollision.h"
#include "../algorithms/CoordinatesCalculation.h"
#include "../algorithms/CollisionAlgorithms.h"

Material::MovingPlayerCollision::MovingPlayerCollision(float analysisStepX, float analysisStepY)
        : MovingCollision(analysisStepX, analysisStepY) {}

Mobs::Player *
Material::MovingPlayerCollision::abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    if (object->getMoveSpeed().xSpeed == 0) return nullptr;

    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {

        if (player.get() == object) continue;

        if (movingAbscissaCollision(objectMinCoordinates, objectMaxCoordinates, *object, *player, ANALYSIS_STEP_Y)) {
            return player.get();
        }
    }
    return nullptr;
}

Mobs::Player *
Material::MovingPlayerCollision::ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    if (object->getMoveSpeed().ySpeed == 0) return nullptr;

    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {

        if (player.get() == object) continue;

        if (movingOrdinateCollision(objectMinCoordinates, objectMaxCoordinates, *object, *player, ANALYSIS_STEP_X)) {
            return player.get();
        }
    }
    return nullptr;
}
