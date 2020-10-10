//
// Created by roman on 25.09.2020.
//

#include "ElasticBlock.h"

Obstacles::ElasticBlock::ElasticBlock(const Obstacles::ObstacleProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                                      const std::shared_ptr<Material::Algorithms> &algorithms)
        : SingleSpriteBlock(properties, sprite, algorithms) {}

void Obstacles::ElasticBlock::selfAction(Unite::Unifier *unifier) {
    this->selfMove(unifier);
}

void Obstacles::ElasticBlock::selfMove(Unite::Unifier *unifier) {

    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {

        if (m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(player.get(), this)) {
            player->setSpeed(Components::Speed(
                    static_cast<int>(-1 * player->getSpeed().xSpeed * m_properties.elasticCoefficient),
                    player->getSpeed().ySpeed));
        }

        if (m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(player.get(), this)) {
            player->setSpeed(Components::Speed(
                    player->getSpeed().xSpeed,
                    static_cast<int>(-1 * player->getSpeed().ySpeed * m_properties.elasticCoefficient)
            ));
        }
    }

    for (const std::shared_ptr<Mobs::Monster> &monster : unifier->getMonsters()) {

        if (m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(monster.get(), this)) {
            monster->setSpeed(Components::Speed(
                    static_cast<int>(-1 * monster->getSpeed().xSpeed * m_properties.elasticCoefficient),
                    monster->getSpeed().ySpeed));
        }

        if (m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(monster.get(), this)) {
            monster->setSpeed(Components::Speed(
                    monster->getSpeed().xSpeed,
                    static_cast<int>(-1 * monster->getSpeed().ySpeed * m_properties.elasticCoefficient)
            ));
        }
    }
}
