//
// Created by roman on 09.09.2020.
//

#include "BasicPlayer.h"

Mobs::BasicPlayer::BasicPlayer(const Mobs::PlayerProperties &properties,
                               const std::shared_ptr<Components::ISpriteBox> &sprite,
                               const std::shared_ptr<Material::Collision> &collision)
        : BasePlayer(properties, sprite, collision) {}

Mobs::BasicPlayer::BasicPlayer(const Mobs::PlayerProperties &properties,
                               const std::shared_ptr<Components::ISpriteBox> &sprite,
                               Material::Collision *collision)
        : BasePlayer(properties, sprite, collision) {}


void Mobs::BasicPlayer::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Mobs::BasicPlayer::selfMove(Unite::Unifier *unifier) {

    Obstacles::Obstacle *obstacle;

    if ((obstacle = m_collision->getObstacleCollision()->abscissaMoveAble(this, unifier)) != nullptr) {
        m_properties.speed.xSpeed = static_cast<int>(-1 * m_properties.speed.xSpeed * obstacle->getProperties().elasticCoefficient);
    }

    if ((obstacle = m_collision->getObstacleCollision()->ordinateMoveAble(this, unifier)) != nullptr) {
        m_properties.speed.ySpeed = static_cast<int>(-1 * m_properties.speed.ySpeed * obstacle->getProperties().elasticCoefficient);
    }

    this->move(m_properties.speed.xSpeed, m_properties.speed.ySpeed);

    if ((m_properties.speed.xSpeed != 0) && (m_properties.speed.ySpeed == 0)) {
        this->addSpeed(m_properties.speed.xSpeed < 0 ? 1 : -1, 0);
    }
}

void Mobs::BasicPlayer::update(const sf::Event &event, sf::RenderWindow &sender) {
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == m_keyMap[KeyAlias::Right])) {
        if ((std::abs(m_properties.speed.xSpeed) < 15) && (m_properties.speed.xSpeed + 3 <= 15)) { this->addSpeed(3, 0); }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == m_keyMap[KeyAlias::Left])) {
        if ((std::abs(m_properties.speed.xSpeed) < 15) && (m_properties.speed.xSpeed - 5 >= -15)) { this->addSpeed(-3, 0); }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == m_keyMap[KeyAlias::Jump])) {
        if (m_properties.speed.ySpeed == 0) { this->addSpeed(0, -15); }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == m_keyMap[KeyAlias::Use])) {
        this->m_sprite->setPosition(600, 100);
    }
}

void Mobs::BasicPlayer::loadKeyMap(const std::string &filename, Managers::DataManager *manager) {
    IniProcessorUtil::Analyzer::IniData keymap = manager->getConfigManager()->loadIni(filename);

    m_keyMap[KeyAlias::Right] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Right"].c_str()));
    m_keyMap[KeyAlias::Left] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Left"].c_str()));
    m_keyMap[KeyAlias::Jump] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Jump"].c_str()));
    m_keyMap[KeyAlias::Use] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Use"].c_str()));
}