//
// Created by roman on 06.10.2020.
//

#include "PlatformBlock.h"

Obstacles::PlatformBlock::PlatformBlock(const Obstacles::ObstacleProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                                        const std::shared_ptr<Material::Algorithms> &algorithms)
        : SingleSpriteBlock(properties, sprite, algorithms) {}

void Obstacles::PlatformBlock::selfAction(Unite::Unifier *unifier) {

    if (m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getBlocks()) != nullptr) {
        m_properties.speed.xSpeed = -1 * m_properties.speed.xSpeed;
    }

    if (m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(this, unifier->getBlocks()) != nullptr) {
        m_properties.speed.ySpeed = -1 * m_properties.speed.ySpeed;
    }

    Mobs::Mob *mob;
    if ((mob = m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getMobs())) != nullptr) {
        bool sameSign = m_properties.speed.xSpeed * mob->getSpeed().xSpeed >= 0;
        float xSpeed = sameSign ? m_properties.speed.xSpeed :
                       (-1 * mob->getSpeed().xSpeed * m_properties.elasticCoefficient) + m_properties.speed.xSpeed;

        mob->setXSpeed(xSpeed);
    }

    if ((mob = m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(this, unifier->getMobs())) != nullptr) {
        bool sameSign = m_properties.speed.ySpeed * mob->getSpeed().ySpeed >= 0;
        float ySpeed = sameSign ? m_properties.speed.ySpeed :
                       (-1 * mob->getSpeed().ySpeed * m_properties.elasticCoefficient) + m_properties.speed.ySpeed;

        mob->setYSpeed(ySpeed);
    }

    for (const std::shared_ptr<Mobs::Mob> &mb : unifier->getMobs()) {
        if ((mb->getSpeed().xSpeed == 0) && m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(mb.get(), this)) {
            mb->setXSpeed(m_properties.speed.xSpeed);
        }
    }
}

