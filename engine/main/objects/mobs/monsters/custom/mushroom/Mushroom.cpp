//
// Created by roman on 17.09.2020.
//

#include "Mushroom.h"

Mobs::Mushroom::Mushroom(const std::shared_ptr<Components::ISpriteBox> &sprite,
                         const std::shared_ptr<Mobs::CollisionStrategy<Obstacles::Obstacle *>> &collision)
        : CollisionProneMonster<Obstacles::Obstacle *>(sprite, collision) {}

Mobs::Mushroom::Mushroom(const std::shared_ptr<Components::ISpriteBox> &sprite,
                         Mobs::CollisionStrategy<Obstacles::Obstacle *> *collision)
        : CollisionProneMonster<Obstacles::Obstacle *>(sprite, collision) {}

void Mobs::Mushroom::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Mobs::Mushroom::selfMove(Unite::Unifier *unifier) {

    Obstacles::Obstacle *obstacle;

    if ((obstacle = _collision->abscissaMoveAble(this)) != nullptr) {
        _speed.xSpeed = -1 * _speed.xSpeed;
    }

    if ((obstacle = _collision->ordinateMoveAble(this)) != nullptr) {
        _speed.ySpeed = static_cast<int>(-1 * _speed.ySpeed * 0.3);
    }

    this->move(_speed.xSpeed, _speed.ySpeed);
}

void Mobs::Mushroom::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}
