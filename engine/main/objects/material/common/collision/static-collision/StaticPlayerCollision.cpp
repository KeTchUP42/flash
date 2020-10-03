//
// Created by roman on 21.09.2020.
//

#include "StaticPlayerCollision.h"
#include "../algorithms/CoordinatesCalculation.h"
#include "../algorithms/CollisionAlgorithms.h"

Mobs::Player *
Material::StaticPlayerCollision::abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {

        if (player.get() == object) continue;

        if (staticAbscissaMoveAble(objectMinCoordinates, objectMaxCoordinates, *object, *player)) {
            return player.get();
        }
    }
    return nullptr;
}


Mobs::Player *
Material::StaticPlayerCollision::ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {

        if (player.get() == object) continue;

        if (staticOrdinateMoveAble(objectMinCoordinates, objectMaxCoordinates, *object, *player)) {
            return player.get();
        }
    }
    return nullptr;
}
