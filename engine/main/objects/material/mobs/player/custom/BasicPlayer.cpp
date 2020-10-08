//
// Created by roman on 09.09.2020.
//

#include "BasicPlayer.h"

Mobs::BasicPlayer::BasicPlayer(const Mobs::PlayerProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                               const std::shared_ptr<Material::Algorithms> &algorithms)
        : BasePlayer(properties, sprite, algorithms) {}

void Mobs::BasicPlayer::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Mobs::BasicPlayer::selfMove(Unite::Unifier *unifier) {

    Obstacles::Obstacle *obstacle;
    if ((obstacle = m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getObstacles())) != nullptr) {
        m_properties.speed.xSpeed = static_cast<int>(-1 * m_properties.speed.xSpeed * obstacle->getProperties().elasticCoefficient);
        if (m_properties.speed.ySpeed != obstacle->getSpeed().ySpeed) {
            m_properties.speed.ySpeed = static_cast<int>(m_properties.speed.ySpeed * obstacle->getProperties().frictionCoefficient);
        }
    }

    if ((obstacle = m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(this, unifier->getObstacles())) != nullptr) {
        m_properties.speed.ySpeed = static_cast<int>(-1 * m_properties.speed.ySpeed * obstacle->getProperties().elasticCoefficient);
        if (m_properties.speed.xSpeed != obstacle->getSpeed().xSpeed) {
            m_properties.speed.xSpeed = static_cast<int>(m_properties.speed.xSpeed * obstacle->getProperties().frictionCoefficient);
        }
    }

    this->move(m_properties.speed.xSpeed, m_properties.speed.ySpeed);
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
        this->m_sprite->setPosition(600, 500);
    }
}

void Mobs::BasicPlayer::loadKeyMap(const std::string &filename, Managers::DataManager *manager) {
    IniUtil::Analyzer::IniData keymap = manager->getConfigManager()->loadIni(filename);

    m_keyMap[KeyAlias::Right] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Right"].c_str()));
    m_keyMap[KeyAlias::Left] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Left"].c_str()));
    m_keyMap[KeyAlias::Jump] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Jump"].c_str()));
    m_keyMap[KeyAlias::Use] = static_cast<sf::Keyboard::Key>(std::atoi(keymap["MAP"]["Use"].c_str()));
}