//
// Created by roman on 17.09.2020.
//

#include "Mushroom.h"

Mobs::Mushroom::Mushroom(const std::shared_ptr<Components::ISpriteBox> &sprite,
                         const std::shared_ptr<Material::ObstacleCollision> &obstacleCollision,
                         const std::shared_ptr<Material::MobCollision> &mobCollision)
        : CollisionProneMonster(sprite, obstacleCollision, mobCollision) {}

Mobs::Mushroom::Mushroom(const std::shared_ptr<Components::ISpriteBox> &sprite,
                         Material::ObstacleCollision *obstacleCollision, Material::MobCollision *mobCollision)
        : CollisionProneMonster(sprite, obstacleCollision, mobCollision) {}

void Mobs::Mushroom::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Mobs::Mushroom::selfMove(Unite::Unifier *unifier) {

    Obstacles::Obstacle *obstacle;

    if ((obstacle = _obstacleCollision->abscissaMoveAble(this)) != nullptr) {
        _speed.xSpeed = -1 * _speed.xSpeed;
    }

    if ((obstacle = _obstacleCollision->ordinateMoveAble(this)) != nullptr) {
        _speed.ySpeed = static_cast<int>(-1 * _speed.ySpeed * 0.3);
    }

    Material::MaterialObject *mob;

    if ((mob = _mobCollision->abscissaMoveAble(this)) != nullptr) {
        if (((_speed.xSpeed < 0) && (mob->getMoveSpeed().xSpeed >= 0)) ||
            ((_speed.xSpeed > 0) && (mob->getMoveSpeed().xSpeed <= 0))) {
            mob->setMoveSpeed(Components::Speed(_speed.xSpeed * 10, mob->getMoveSpeed().ySpeed - 10));
        }
    }

    this->move(_speed.xSpeed, _speed.ySpeed);
}

void Mobs::Mushroom::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}

