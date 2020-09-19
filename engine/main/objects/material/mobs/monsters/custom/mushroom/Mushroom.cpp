//
// Created by roman on 17.09.2020.
//

#include "Mushroom.h"

Mobs::Mushroom::Mushroom(const std::shared_ptr<Components::ISpriteBox> &sprite,
                         const std::shared_ptr<Material::Collision> &collision)
        : CollisionProneMonster(sprite, collision) {}

Mobs::Mushroom::Mushroom(const std::shared_ptr<Components::ISpriteBox> &sprite,
                         Material::Collision *collision)
        : CollisionProneMonster(sprite, collision) {}

void Mobs::Mushroom::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Mobs::Mushroom::selfMove(Unite::Unifier *unifier) {

    Obstacles::Obstacle *obstacle;

    if ((obstacle = _collision->getObstacleCollision()->abscissaMoveAble(this)) != nullptr) {
        _speed.xSpeed = -1 * _speed.xSpeed;
    }

    if ((obstacle = _collision->getObstacleCollision()->ordinateMoveAble(this)) != nullptr) {
        _speed.ySpeed = static_cast<int>(-1 * _speed.ySpeed * 0.3);
    }

    Mobs::Player *player;

    if ((player = _collision->getPlayerCollision()->abscissaMoveAble(this)) != nullptr) {
        if (((_speed.xSpeed < 0) && (player->getMoveSpeed().xSpeed >= 0)) ||
            ((_speed.xSpeed > 0) && (player->getMoveSpeed().xSpeed <= 0))) {
            player->setMoveSpeed(Components::Speed(_speed.xSpeed * 5, player->getMoveSpeed().ySpeed - 10));
        }
    }

    this->move(_speed.xSpeed, _speed.ySpeed);
}

void Mobs::Mushroom::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}

