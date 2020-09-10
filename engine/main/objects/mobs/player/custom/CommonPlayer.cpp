//
// Created by roman on 09.09.2020.
//

#include "CommonPlayer.h"

Mobs::CommonPlayer::CommonPlayer(const std::shared_ptr<Components::ISpriteBox> &sprite) : Player(sprite) {}

void Mobs::CommonPlayer::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
    //..
}

void Mobs::CommonPlayer::selfMove(Unite::Unifier *unifier) {
    //todo: Testing can player move?
    this->move(_speed.xSpeed, _speed.ySpeed);
    if (_speed.xSpeed != 0)
        this->addSpeed(_speed.xSpeed < 0 ? 1 : -1, _speed.ySpeed);
    if (_speed.ySpeed != 0)
        this->addSpeed(_speed.xSpeed, _speed.ySpeed < 0 ? 1 : -1);
    //..
}

void Mobs::CommonPlayer::update(const sf::Event &event, sf::RenderWindow &sender) {
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == _keyMap[KeyAlias::Right]))
        this->addSpeed(5, 0);
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == _keyMap[KeyAlias::Left]))
        this->addSpeed(-5, 0);
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == _keyMap[KeyAlias::Jump]))
        this->addSpeed(0, -5);
}

