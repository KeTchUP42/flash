//
// Created by roman on 25.09.2020.
//

#include "ElasticBlock.h"

Obstacles::ElasticBlock::ElasticBlock(const Obstacles::ObstacleProperties &properties,
                                      const std::shared_ptr<Components::ISpriteBox> &sprite,
                                      const std::shared_ptr<Material::Collision> &collision)
        : SingleSpriteBlock(properties, sprite, collision) {}

void Obstacles::ElasticBlock::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Obstacles::ElasticBlock::selfMove(Unite::Unifier *unifier) {

    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {

        Obstacles::Obstacle *obstacle;

        if ((obstacle = m_collision->getObstacleCollision()->abscissaMoveAble(player.get(), unifier)) != nullptr) {
            if (obstacle == this) {
                player->setMoveSpeed(Components::Speed(
                        static_cast<int>(-1 * player->getMoveSpeed().xSpeed * obstacle->getProperties().elasticCoefficient),
                        player->getMoveSpeed().ySpeed));
            }
        }

        if ((obstacle = m_collision->getObstacleCollision()->ordinateMoveAble(player.get(), unifier)) != nullptr) {
            if (obstacle == this) {
                player->setMoveSpeed(Components::Speed(
                        player->getMoveSpeed().xSpeed,
                        static_cast<int>(-1 * player->getMoveSpeed().ySpeed * obstacle->getProperties().elasticCoefficient)
                ));
            }
        }
    }

    for (const std::shared_ptr<Mobs::Monster> &monster : unifier->getMonsters()) {

        Obstacles::Obstacle *obstacle;

        if ((obstacle = m_collision->getObstacleCollision()->abscissaMoveAble(monster.get(), unifier)) != nullptr) {
            if (obstacle == this) {
                monster->setMoveSpeed(Components::Speed(
                        static_cast<int>(-1 * monster->getMoveSpeed().xSpeed * obstacle->getProperties().elasticCoefficient),
                        monster->getMoveSpeed().ySpeed));
            }
        }

        if ((obstacle = m_collision->getObstacleCollision()->ordinateMoveAble(monster.get(), unifier)) != nullptr) {
            if (obstacle == this) {
                monster->setMoveSpeed(Components::Speed(
                        monster->getMoveSpeed().xSpeed,
                        static_cast<int>(-1 * monster->getMoveSpeed().ySpeed * obstacle->getProperties().elasticCoefficient)
                ));
            }
        }
    }

    this->move(m_properties.speed.xSpeed, m_properties.speed.ySpeed);
}

void Obstacles::ElasticBlock::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}
