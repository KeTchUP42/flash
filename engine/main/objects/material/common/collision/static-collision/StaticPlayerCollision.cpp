//
// Created by roman on 21.09.2020.
//

#include "StaticPlayerCollision.h"
#include "../coordinates/CoordinatesCalculation.h"
#include "additionally/ExtremeCoordinates.h"

Material::StaticPlayerCollision::StaticPlayerCollision(Unite::Unifier *unifier) : CollisionStrategy(unifier) {}

Mobs::Player *Material::StaticPlayerCollision::abscissaMoveAble(Material::MaterialObject *object) const noexcept {
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

        //Optimization.
        if (playerMaxCoordinates.x > objectMaxCoordinates.x) {
            if (playerMinCoordinates.x - objectMaxCoordinates.x > 0) continue;
        } else {
            if (objectMinCoordinates.x - playerMaxCoordinates.x > 0) continue;
        }

        float objectSuperfluousX = ((playerMaxCoordinates.x > objectMaxCoordinates.x)
                                    ? objectMinCoordinates.x : objectMaxCoordinates.x);

        for (const Components::Point &point : extremeCoordinatesAbscissa(*object, objectSuperfluousX)) {
            if (player->collision(point.x, point.y)) {
                return player.get();
            }
        }

        float playerSuperfluousX = ((playerMaxCoordinates.x > objectMaxCoordinates.x)
                                    ? playerMaxCoordinates.x : playerMinCoordinates.x);

        for (const Components::Point &point : extremeCoordinatesAbscissa(*player, playerSuperfluousX)) {
            if (object->collision(point.x, point.y)) {
                return player.get();
            }
        }
    }
    return nullptr;
}

Mobs::Player *Material::StaticPlayerCollision::ordinateMoveAble(Material::MaterialObject *object) const noexcept {
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

        //Optimization.
        if (playerMaxCoordinates.y > objectMaxCoordinates.y) {
            if (playerMinCoordinates.y - objectMaxCoordinates.y > 0) continue;
        } else {
            if (objectMinCoordinates.y - playerMaxCoordinates.y > 0) continue;
        }

        float objectSuperfluousY = ((playerMaxCoordinates.y > objectMaxCoordinates.y)
                                    ? objectMinCoordinates.y : objectMaxCoordinates.y);

        for (const Components::Point &point : extremeCoordinatesOrdinate(*object, objectSuperfluousY)) {
            if (player->collision(point.x, point.y)) {
                return player.get();
            }
        }

        float obstacleSuperfluousY = ((playerMaxCoordinates.y > objectMaxCoordinates.y)
                                      ? playerMaxCoordinates.y : playerMinCoordinates.y);

        for (const Components::Point &point : extremeCoordinatesOrdinate(*player, obstacleSuperfluousY)) {
            if (object->collision(point.x, point.y)) {
                return player.get();
            }
        }
    }
    return nullptr;
}
