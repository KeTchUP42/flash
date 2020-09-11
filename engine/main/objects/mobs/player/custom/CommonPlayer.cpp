//
// Created by roman on 09.09.2020.
//

#include "CommonPlayer.h"

Mobs::CommonPlayer::CommonPlayer(const std::shared_ptr<Components::ISpriteBox> &sprite) : Player(sprite) {}

void Mobs::CommonPlayer::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Mobs::CommonPlayer::selfMove(Unite::Unifier *unifier) {
    //todo: Testing can player move?
    this->move(_speed.xSpeed, _speed.ySpeed);
    this->rotate(0.5, 500, 500);
    if (_speed.xSpeed != 0)
        this->addSpeed(_speed.xSpeed < 0 ? 1 : -1, 0);
    if (_speed.ySpeed != 0)
        this->addSpeed(0, _speed.ySpeed < 0 ? 0.5 : -0.5);
    //..
}

void Mobs::CommonPlayer::update(const sf::Event &event, sf::RenderWindow &sender) {
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == _keyMap[KeyAlias::Right])) {
        if ((std::abs(_speed.xSpeed) < 20) && (_speed.xSpeed + 5 <= 20)) { this->addSpeed(5, 0); }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == _keyMap[KeyAlias::Left])) {
        if ((std::abs(_speed.xSpeed) < 20) && (_speed.xSpeed - 5 >= -20)) { this->addSpeed(-5, 0); }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == _keyMap[KeyAlias::Jump])) {
        if (_speed.ySpeed >= 0) { this->addSpeed(0, -10); }
    }
}

void Mobs::CommonPlayer::loadKeyMap(const std::string &filename, Managers::DataManager *manager) {
    IniProcessorUtil::Analyzer::IniData keymap = manager->getConfigManager()->loadIni(filename);

    std::map<KeyAlias, sf::Keyboard::Key> keys;
    keys[KeyAlias::Right] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Right"].c_str()));
    keys[KeyAlias::Left] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Left"].c_str()));
    keys[KeyAlias::Jump] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Jump"].c_str()));
    keys[KeyAlias::ShootR] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["ShootR"].c_str()));
    keys[KeyAlias::ShootL] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["ShootL"].c_str()));
    keys[KeyAlias::Use] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Use"].c_str()));
    Player::loadKeyMap(keys);
}