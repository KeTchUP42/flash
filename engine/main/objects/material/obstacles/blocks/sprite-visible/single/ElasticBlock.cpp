//
// Created by roman on 25.09.2020.
//

#include "ElasticBlock.h"

Obstacles::ElasticBlock::ElasticBlock(const Obstacles::ObstacleProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                                      const std::shared_ptr<Material::Algorithms> &algorithms)
        : SingleSpriteBlock(properties, sprite, algorithms) {}

void Obstacles::ElasticBlock::selfAction(Unite::Unifier *unifier) {

    for (const std::shared_ptr<Mobs::Mob> &mob : unifier->getMobs()) {

        if (m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(mob.get(), this)) {
            mob->setXSpeed(static_cast<int>(-1 * mob->getSpeed().xSpeed * m_properties.elasticCoefficient));
        }

        if (m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(mob.get(), this)) {
            mob->setYSpeed(static_cast<int>(-1 * mob->getSpeed().ySpeed * m_properties.elasticCoefficient));
        }
    }
}
