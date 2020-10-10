//
// Created by roman on 06.10.2020.
//

#include "PlatformBlock.h"

Obstacles::PlatformBlock::PlatformBlock(const Obstacles::ObstacleProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                                        const std::shared_ptr<Material::Algorithms> &algorithms)
        : SingleSpriteBlock(properties, sprite, algorithms) {}

void Obstacles::PlatformBlock::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Obstacles::PlatformBlock::selfMove(Unite::Unifier *unifier) {

    if (m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getObstacles()) != nullptr) {
        m_properties.speed.xSpeed = -1 * m_properties.speed.xSpeed;
    }

    if (m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(this, unifier->getObstacles()) != nullptr) {
        m_properties.speed.ySpeed = -1 * m_properties.speed.ySpeed;
    }

    Mobs::Monster *monster;
    if ((monster = m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getMonsters())) != nullptr) {
        bool sameSign = m_properties.speed.xSpeed * monster->getSpeed().xSpeed >= 0;
        float xSpeed = sameSign ? m_properties.speed.xSpeed :
                       (-1 * monster->getSpeed().xSpeed * m_properties.elasticCoefficient) + m_properties.speed.xSpeed;

        monster->setSpeed(Components::Speed(xSpeed, monster->getProperties().speed.ySpeed));
    }

    if ((monster = m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(this, unifier->getMonsters())) != nullptr) {
        bool sameSign = m_properties.speed.ySpeed * monster->getSpeed().ySpeed >= 0;
        float ySpeed = sameSign ? m_properties.speed.ySpeed :
                       (-1 * monster->getSpeed().ySpeed * m_properties.elasticCoefficient) + m_properties.speed.ySpeed;

        monster->setSpeed(Components::Speed(monster->getProperties().speed.xSpeed, ySpeed));
    }

    Mobs::Player *player;
    if ((player = m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getPlayers())) != nullptr) {
        bool sameSign = m_properties.speed.xSpeed * player->getSpeed().xSpeed >= 0;
        float xSpeed = sameSign ? m_properties.speed.xSpeed :
                       (-1 * player->getSpeed().xSpeed * m_properties.elasticCoefficient) + m_properties.speed.xSpeed;

        player->setSpeed(Components::Speed(xSpeed, player->getProperties().speed.ySpeed));
    }

    if ((player = m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(this, unifier->getPlayers())) != nullptr) {
        bool sameSign = m_properties.speed.ySpeed * player->getSpeed().ySpeed >= 0;
        float ySpeed = sameSign ? m_properties.speed.ySpeed :
                       (-1 * player->getSpeed().ySpeed * m_properties.elasticCoefficient) + m_properties.speed.ySpeed;

        player->setSpeed(Components::Speed(player->getProperties().speed.xSpeed, ySpeed));
    }

    for (const std::shared_ptr<Mobs::Player> &plyr : unifier->getPlayers()) {
        if (plyr->getSpeed().xSpeed == 0) {
            if (m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(plyr.get(), this)) {
                plyr->setSpeed(Components::Speed(m_properties.speed.xSpeed, plyr->getSpeed().ySpeed));
            }
        }
    }

    for (const std::shared_ptr<Mobs::Monster> &monstr : unifier->getMonsters()) {
        if (monstr->getSpeed().xSpeed == 0) {
            if (m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(monstr.get(), this)) {
                monstr->setSpeed(Components::Speed(m_properties.speed.xSpeed, monstr->getSpeed().ySpeed));
            }
        }
    }
}
