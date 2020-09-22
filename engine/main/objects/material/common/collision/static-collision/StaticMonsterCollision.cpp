//
// Created by roman on 21.09.2020.
//

#include "StaticMonsterCollision.h"
#include "../coordinates/CoordinatesCalculation.h"
#include "additionally/ExtraCoordinates.h"

Material::StaticMonsterCollision::StaticMonsterCollision(Unite::Unifier *unifier) : CollisionStrategy(unifier) {}

Mobs::Monster *Material::StaticMonsterCollision::abscissaMoveAble(Material::MaterialObject *object) const noexcept {
    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Monster> &monster : _unifier->getMonsters()) {

        if (monster.get() == object) continue;

        Components::Point monsterMinCoordinates = minCoordinates(*monster);
        Components::Point monsterMaxCoordinates = maxCoordinates(*monster);

        if (!((((objectMinCoordinates.y >= monsterMinCoordinates.y) && (objectMinCoordinates.y <= monsterMaxCoordinates.y)) ||
               ((objectMaxCoordinates.y >= monsterMinCoordinates.y) && (objectMaxCoordinates.y <= monsterMaxCoordinates.y))) ||
              (((monsterMinCoordinates.y >= objectMinCoordinates.y) && (monsterMinCoordinates.y <= objectMaxCoordinates.y)) ||
               ((monsterMaxCoordinates.y >= objectMinCoordinates.y) && (monsterMaxCoordinates.y <= objectMaxCoordinates.y)))))
            continue; //Takes only monster with valid position.

        //Optimization.
        if (monsterMaxCoordinates.x > objectMaxCoordinates.x) {
            if (monsterMinCoordinates.x - objectMaxCoordinates.x > 0) continue;
        } else {
            if (objectMinCoordinates.x - monsterMaxCoordinates.x > 0) continue;
        }

        float objectSuperfluousX = ((monsterMaxCoordinates.x > objectMaxCoordinates.x)
                                    ? objectMinCoordinates.x : objectMaxCoordinates.x);

        for (const Components::Point &point : extremeCoordinatesAbscissa(*object, objectSuperfluousX)) {
            if (monster->collision(point.x, point.y)) {
                return monster.get();
            }
        }

        float monsterSuperfluousX = ((monsterMaxCoordinates.x > objectMaxCoordinates.x)
                                     ? monsterMaxCoordinates.x : monsterMinCoordinates.x);

        for (const Components::Point &point : extremeCoordinatesAbscissa(*monster, monsterSuperfluousX)) {
            if (object->collision(point.x, point.y)) {
                return monster.get();
            }
        }
    }
    return nullptr;
}

Mobs::Monster *Material::StaticMonsterCollision::ordinateMoveAble(Material::MaterialObject *object) const noexcept {
    Components::Point objectMinCoordinates = minCoordinates(*object);
    Components::Point objectMaxCoordinates = maxCoordinates(*object);

    for (const std::shared_ptr<Mobs::Monster> &monster : _unifier->getMonsters()) {

        if (monster.get() == object) continue;

        Components::Point monsterMinCoordinates = minCoordinates(*monster);
        Components::Point monsterMaxCoordinates = maxCoordinates(*monster);

        if (!((((objectMinCoordinates.x >= monsterMinCoordinates.x) && (objectMinCoordinates.x <= monsterMaxCoordinates.x)) ||
               ((objectMaxCoordinates.x >= monsterMinCoordinates.x) && (objectMaxCoordinates.x <= monsterMaxCoordinates.x))) ||
              (((monsterMinCoordinates.x >= objectMinCoordinates.x) && (monsterMinCoordinates.x <= objectMaxCoordinates.x)) ||
               ((monsterMaxCoordinates.x >= objectMinCoordinates.x) && (monsterMaxCoordinates.x <= objectMaxCoordinates.x)))))
            continue; //Takes only monster with valid position.

        //Optimization.
        if (monsterMaxCoordinates.y > objectMaxCoordinates.y) {
            if (monsterMinCoordinates.y - objectMaxCoordinates.y > 0) continue;
        } else {
            if (objectMinCoordinates.y - monsterMaxCoordinates.y > 0) continue;
        }

        float objectSuperfluousY = ((monsterMaxCoordinates.y > objectMaxCoordinates.y)
                                    ? objectMinCoordinates.y : objectMaxCoordinates.y);

        for (const Components::Point &point : extremeCoordinatesOrdinate(*object, objectSuperfluousY)) {
            if (monster->collision(point.x, point.y)) {
                return monster.get();
            }
        }

        float monsterSuperfluousY = ((monsterMaxCoordinates.y > objectMaxCoordinates.y)
                                     ? monsterMaxCoordinates.y : monsterMinCoordinates.y);

        for (const Components::Point &point : extremeCoordinatesOrdinate(*monster, monsterSuperfluousY)) {
            if (object->collision(point.x, point.y)) {
                return monster.get();
            }
        }
    }
    return nullptr;
}