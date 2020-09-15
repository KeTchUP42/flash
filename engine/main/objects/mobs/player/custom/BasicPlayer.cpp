//
// Created by roman on 09.09.2020.
//

#include "BasicPlayer.h"

Mobs::BasicPlayer::BasicPlayer(const std::shared_ptr<Components::ISpriteBox> &sprite,
                               const std::shared_ptr<CollisionStrategy<Obstacles::Obstacle *>> &collision)
        : _collision(collision), Player(sprite) {}

Mobs::BasicPlayer::BasicPlayer(const std::shared_ptr<Components::ISpriteBox> &sprite,
                               Mobs::CollisionStrategy<Obstacles::Obstacle *> *collision)
        : _collision(collision), Player(sprite) {}

void Mobs::BasicPlayer::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Mobs::BasicPlayer::selfMove(Unite::Unifier *unifier) {

    Obstacles::Obstacle *obstacle;

    if ((obstacle = _collision->abscissaMoveAble(this)) != nullptr) {
        _speed.xSpeed = static_cast<int>(-1 * _speed.xSpeed * 0.49);  // You can use coefficient of elasticity.
    }

    if ((obstacle = _collision->ordinateMoveAble(this)) != nullptr) {
        _speed.ySpeed = static_cast<int>(-1 * _speed.ySpeed * 0.49);  // You can use coefficient of elasticity.
    }

    this->move(_speed.xSpeed, _speed.ySpeed);

    if ((_speed.xSpeed != 0) && (_speed.ySpeed == 0)) {
        this->addSpeed(_speed.xSpeed < 0 ? 1 : -1, 0);
    }
}

void Mobs::BasicPlayer::update(const sf::Event &event, sf::RenderWindow &sender) {
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == _keyMap[KeyAlias::Right])) {
        if ((std::abs(_speed.xSpeed) < 15) && (_speed.xSpeed + 3 <= 15)) { this->addSpeed(3, 0); }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == _keyMap[KeyAlias::Left])) {
        if ((std::abs(_speed.xSpeed) < 15) && (_speed.xSpeed - 5 >= -15)) { this->addSpeed(-3, 0); }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == _keyMap[KeyAlias::Jump])) {
        if (_speed.ySpeed >= 0) { this->addSpeed(0, -15); }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == _keyMap[KeyAlias::Use])) {
        this->_sprite->setPosition(600, 100);
    }
}

void Mobs::BasicPlayer::loadKeyMap(const std::string &filename, Managers::DataManager *manager) {
    IniProcessorUtil::Analyzer::IniData keymap = manager->getConfigManager()->loadIni(filename);

    _keyMap[KeyAlias::Right] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Right"].c_str()));
    _keyMap[KeyAlias::Left] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Left"].c_str()));
    _keyMap[KeyAlias::Jump] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Jump"].c_str()));
    _keyMap[KeyAlias::ShootR] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["ShootR"].c_str()));
    _keyMap[KeyAlias::ShootL] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["ShootL"].c_str()));
    _keyMap[KeyAlias::Use] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Use"].c_str()));
}