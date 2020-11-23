//
// Created by roman on 17.09.2020.
//

#include "Mushroom.h"

Mobs::Mushroom::Mushroom(
        const Mobs::MobProperties &properties,
        const Components::Area &area,
        const std::shared_ptr<Components::ISpriteBox> &sprite,
        const std::shared_ptr<Material::Algorithms> &algorithms,
        const Mobs::MushroomProperties &params
) : BaseMob(properties, area, sprite, algorithms), m_mushroom(params) {}

void Mobs::Mushroom::selfAction(Unite::Unifier *unifier) {
    this->staticPropertyAnalysis();
    if (this->isDead()) {
        unifier->addFrameAction([this](Unite::Unifier *unifier1) -> void {
            unifier1->removeMob(this);
        });
    } else {
        for (Mobs::Player *player : unifier->getPlayers()) {
            if (m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(player, this)) {
                if (player->getPosition().y < this->getPosition().y) {
                    player->setSpeed(Components::Speed(
                            player->getSpeed().xSpeed,
                            static_cast<int>(-1 * (player->getSpeed().ySpeed + player->getSpeed().ySpeed * m_mushroom.elasticityLevel))
                    ));
                }
            }
        }
        Mobs::Mob *mob;
        if ((mob = m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getMobs())) != nullptr) {
            if (this->getSpeed().xSpeed * mob->getSpeed().xSpeed <= 0) {
                mob->setSpeed(Components::Speed((this->getSpeed().xSpeed > 0 ? 1 : -1) * m_mushroom.punchPower,
                                                mob->getSpeed().ySpeed - m_mushroom.punchPower * 2));

                if (std::abs(m_mushroom.punchPower) > std::abs(this->getSpeed().xSpeed)) {
                    m_properties.speed.xSpeed = 0;
                } else {
                    m_properties.speed.xSpeed = -this->getSpeed().xSpeed + m_mushroom.punchPower *
                            ((this->getSpeed().xSpeed > 0 ? -1 : 1) * (m_mushroom.punchPower > 0 ? -1 : 1));
                }
            }
        }

        if (m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getObstacles()) != nullptr) {
            m_properties.speed.xSpeed = static_cast<int>(-1 * m_properties.speed.xSpeed);
        }

        Obstacles::Block *block;
        if ((block = m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(this, unifier->getBlocks())) != nullptr) {
            bool sameSign = m_properties.speed.ySpeed * block->getSpeed().ySpeed >= 0;
            float ySpeed = static_cast<int>(-1 * m_properties.speed.ySpeed * block->getProperties().elasticCoefficient + (sameSign ? 0 : block->getSpeed().ySpeed));
            m_properties.speed.ySpeed = (std::abs(ySpeed) == 1) ? 0 : ySpeed;
        }
    }
}
