//
// Created by roman on 21.09.2020.
//

#include "StaticMonsterCollision.h"
#include "../algorithms/CoordinatesCalculation.h"
#include "../algorithms/CollisionAlgorithms.h"

Mobs::Monster *
Material::StaticMonsterCollision::abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Monster> &monster : unifier->getMonsters()) {

        if (monster.get() == object) continue;

        if (staticAbscissaMoveAble(objectMinCoordinates, objectMaxCoordinates, *object, *monster)) {
            return monster.get();
        }
    }
    return nullptr;
}

Mobs::Monster *
Material::StaticMonsterCollision::ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Monster> &monster : unifier->getMonsters()) {

        if (monster.get() == object) continue;

        if (staticOrdinateMoveAble(objectMinCoordinates, objectMaxCoordinates, *object, *monster)) {
            return monster.get();
        }
    }
    return nullptr;
}
