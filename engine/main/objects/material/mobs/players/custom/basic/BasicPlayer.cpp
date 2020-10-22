//
// Created by roman on 09.09.2020.
//

#include "BasicPlayer.h"

Mobs::BasicPlayer::BasicPlayer(const Mobs::MobProperties &properties, const Components::Area &area,
                               const std::shared_ptr<Components::ISpriteBox> &sprite, const std::shared_ptr<Material::Algorithms> &algorithms,
                               const Mobs::BasicPlayerProperties &params)
        : BasePlayer(properties, area, sprite, algorithms), m_basic(params) {}

void Mobs::BasicPlayer::selfAction(Unite::Unifier *unifier) {
    if (m_properties.healthPoints <= 0) {
        m_properties.isRemovable = true;
    } else {
        this->selfMove(unifier);
    }
}

void Mobs::BasicPlayer::selfMove(Unite::Unifier *unifier) {

    Obstacles::Obstacle *obstacle;
    if ((obstacle = m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getObstacles())) != nullptr) {
        bool sameSign = m_properties.speed.xSpeed * obstacle->getSpeed().xSpeed >= 0;
        float xSpeed = static_cast<int>(-1 * m_properties.speed.xSpeed * obstacle->getProperties().elasticCoefficient +
                                        (sameSign ? 0 : obstacle->getSpeed().xSpeed));
        m_properties.speed.xSpeed = (std::abs(xSpeed) == 1) ? 0 : xSpeed;
        if (m_properties.speed.ySpeed != obstacle->getSpeed().ySpeed) {
            m_properties.speed.ySpeed = static_cast<int>(m_properties.speed.ySpeed * obstacle->getProperties().frictionCoefficient);
        }
    }

    if ((obstacle = m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(this, unifier->getObstacles())) != nullptr) {
        bool sameSign = m_properties.speed.ySpeed * obstacle->getSpeed().ySpeed >= 0;
        float ySpeed = static_cast<int>(-1 * m_properties.speed.ySpeed * obstacle->getProperties().elasticCoefficient +
                                        (sameSign ? 0 : obstacle->getSpeed().ySpeed));
        m_properties.speed.ySpeed = (std::abs(ySpeed) == 1) ? 0 : ySpeed;
        if (m_properties.speed.xSpeed != obstacle->getSpeed().xSpeed) {
            m_properties.speed.xSpeed = static_cast<int>(m_properties.speed.xSpeed * obstacle->getProperties().frictionCoefficient);
        }
    }
}

void Mobs::BasicPlayer::update(const sf::Event &event, sf::RenderWindow &sender) {
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == m_keyMap[KeyAlias::Right])) {
        if ((std::abs(m_properties.speed.xSpeed) < m_basic.maxMoveSpeed) && (m_properties.speed.xSpeed + m_basic.moveSpeed <= m_basic.maxMoveSpeed)) {
            this->addSpeed(m_basic.moveSpeed, 0);
        }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == m_keyMap[KeyAlias::Left])) {
        if ((std::abs(m_properties.speed.xSpeed) < m_basic.maxMoveSpeed) && (m_properties.speed.xSpeed - m_basic.moveSpeed >= -m_basic.maxMoveSpeed)) {
            this->addSpeed(-m_basic.moveSpeed, 0);
        }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == m_keyMap[KeyAlias::Jump])) {
        if (m_properties.speed.ySpeed == 0) { this->addSpeed(0, -m_basic.jumpSpeed); }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == m_keyMap[KeyAlias::Use])) {
        //..
    }
}