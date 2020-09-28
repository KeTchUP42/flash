//
// Created by roman on 17.09.2020.
//

#include "Mushroom.h"

Mobs::Mushroom::Mushroom(const Mobs::MonsterProperties &properties,
                         const std::shared_ptr<Components::ISpriteBox> &sprite,
                         const std::shared_ptr<Material::Collision> &collision)
        : BaseMonster(properties, sprite, collision) {}

Mobs::Mushroom::Mushroom(const Mobs::MonsterProperties &properties,
                         const std::shared_ptr<Components::ISpriteBox> &sprite,
                         Material::Collision *collision)
        : BaseMonster(properties, sprite, collision) {}

void Mobs::Mushroom::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Mobs::Mushroom::selfMove(Unite::Unifier *unifier) {

    Obstacles::Obstacle *obstacle;
    if ((obstacle = m_collision->getObstacleCollision()->abscissaMoveAble(this, unifier)) != nullptr) {
        m_properties.speed.xSpeed = static_cast<int>(-1 * m_properties.speed.xSpeed);
    }

    if ((obstacle = m_collision->getObstacleCollision()->ordinateMoveAble(this, unifier)) != nullptr) {
        m_properties.speed.ySpeed = static_cast<int>(-1 * m_properties.speed.ySpeed * obstacle->getProperties().elasticCoefficient);
    }

    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {
        Mobs::Monster *me;
        if ((me = m_collision->getMonsterCollision()->ordinateMoveAble(player.get(), unifier)) != nullptr) {
            if (me == this) {
                player->setMoveSpeed(Components::Speed(
                        player->getMoveSpeed().xSpeed,
                        static_cast<int>(-1 * (player->getMoveSpeed().ySpeed + player->getMoveSpeed().ySpeed * 0.25))
                ));
            }
        }
    }

    Mobs::Monster *monster;
    if ((monster = m_collision->getMonsterCollision()->abscissaMoveAble(this, unifier)) != nullptr) {
        if (((m_properties.speed.xSpeed < 0) && (monster->getMoveSpeed().xSpeed >= 0)) ||
            ((m_properties.speed.xSpeed > 0) && (monster->getMoveSpeed().xSpeed <= 0))) {
            monster->setMoveSpeed(Components::Speed(m_properties.speed.xSpeed > 0 ? 5 : -5, monster->getMoveSpeed().ySpeed - 10));
            m_properties.speed.xSpeed += m_properties.speed.xSpeed > 0 ? -1 : 1;
        }
    }

    this->move(m_properties.speed.xSpeed, m_properties.speed.ySpeed);
}

void Mobs::Mushroom::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}

