//
// Created by roman on 17.09.2020.
//

#include "Mushroom.h"

Mobs::Mushroom::Mushroom(const Mobs::MonsterProperties &properties,
                         const std::shared_ptr<Components::ISpriteBox> &sprite,
                         const std::shared_ptr<Material::Collision> &collision)
        : BaseMonster(properties, sprite, collision) {}

Mobs::Mushroom::Mushroom(const Mobs::MonsterProperties &properties,
                         const std::shared_ptr<Components::ISpriteBox> &sprite,
                         Material::Collision *collision)
        : BaseMonster(properties, sprite, collision) {}

void Mobs::Mushroom::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Mobs::Mushroom::selfMove(Unite::Unifier *unifier) {

    Obstacles::Obstacle *obstacle;
    if ((obstacle = _collision->getObstacleCollision()->abscissaMoveAble(this, unifier)) != nullptr) {
        _properties.speed.xSpeed = static_cast<int>(-1 * _properties.speed.xSpeed);
    }

    if ((obstacle = _collision->getObstacleCollision()->ordinateMoveAble(this, unifier)) != nullptr) {
        _properties.speed.ySpeed = static_cast<int>(-1 * _properties.speed.ySpeed * obstacle->getProperties().elasticCoefficient);
    }

    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {
        Mobs::Monster *me;
        if ((me = _collision->getMonsterCollision()->ordinateMoveAble(player.get(), unifier)) != nullptr) {
            if (me == this) {
                player->setMoveSpeed(Components::Speed(
                        player->getMoveSpeed().xSpeed,
                        static_cast<int>(-1 * (player->getMoveSpeed().ySpeed + player->getMoveSpeed().ySpeed * 0.25))
                ));
            }
        }
    }

    Mobs::Monster *monster;
    if ((monster = _collision->getMonsterCollision()->abscissaMoveAble(this, unifier)) != nullptr) {
        if (((_properties.speed.xSpeed < 0) && (monster->getMoveSpeed().xSpeed >= 0)) ||
            ((_properties.speed.xSpeed > 0) && (monster->getMoveSpeed().xSpeed <= 0))) {
            monster->setMoveSpeed(Components::Speed(_properties.speed.xSpeed > 0 ? 5 : -5, monster->getMoveSpeed().ySpeed - 10));
            _properties.speed.xSpeed += _properties.speed.xSpeed > 0 ? -1 : 1;
        }
    }

    this->move(_properties.speed.xSpeed, _properties.speed.ySpeed);
}

void Mobs::Mushroom::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}

