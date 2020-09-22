//
// Created by roman on 17.09.2020.
//

#include "Mushroom.h"

Mobs::Mushroom::Mushroom(const std::shared_ptr<Components::ISpriteBox> &sprite,
                         const std::shared_ptr<Material::Collision> &collision)
        : BaseMonster(sprite, collision) {}

Mobs::Mushroom::Mushroom(const std::shared_ptr<Components::ISpriteBox> &sprite,
                         Material::Collision *collision)
        : BaseMonster(sprite, collision) {}

void Mobs::Mushroom::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Mobs::Mushroom::selfMove(Unite::Unifier *unifier) {

    Obstacles::Obstacle *obstacle;

    if ((obstacle = _collision->getObstacleCollision()->abscissaMoveAble(this)) != nullptr) {
        _speed.xSpeed = static_cast<int>(-1 * _speed.xSpeed * obstacle->getElasticCoefficient());
    }

    if ((obstacle = _collision->getObstacleCollision()->ordinateMoveAble(this)) != nullptr) {
        _speed.ySpeed = static_cast<int>(-1 * _speed.ySpeed * obstacle->getElasticCoefficient());
    }

    Mobs::Monster *monster;

    if ((monster = _collision->getMonsterCollision()->abscissaMoveAble(this)) != nullptr) {
        if (((_speed.xSpeed < 0) && (monster->getMoveSpeed().xSpeed >= 0)) ||
            ((_speed.xSpeed > 0) && (monster->getMoveSpeed().xSpeed <= 0))) {
            monster->setMoveSpeed(Components::Speed(_speed.xSpeed > 0 ? 5 : -5, monster->getMoveSpeed().ySpeed - 10));
            _speed.xSpeed += _speed.xSpeed > 0 ? -1 : 1;
        }
    }

    this->move(_speed.xSpeed, _speed.ySpeed);
}

void Mobs::Mushroom::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}

