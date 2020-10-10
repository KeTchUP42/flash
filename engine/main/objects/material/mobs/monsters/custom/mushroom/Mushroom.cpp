//
// Created by roman on 17.09.2020.
//

#include "Mushroom.h"

Mobs::Mushroom::Mushroom(const Mobs::MonsterProperties &properties, const Components::Area &area,
                         const std::shared_ptr<Components::ISpriteBox> &sprite, const std::shared_ptr<Material::Algorithms> &algorithms)
        : BaseMonster(properties, area, sprite, algorithms), m_mind(this) {}

void Mobs::Mushroom::selfAction(Unite::Unifier *unifier) {
    m_mind.analyze(unifier);
}

void Mobs::Mushroom::selfMove(Unite::Unifier *unifier) {

    Obstacles::Obstacle *obstacle;
    if ((obstacle = m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getObstacles())) != nullptr) {
        m_properties.speed.xSpeed = static_cast<int>(-1 * m_properties.speed.xSpeed);
    }

    if ((obstacle = m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(this, unifier->getObstacles())) != nullptr) {
        float ySpeed = static_cast<int>(-1 * m_properties.speed.ySpeed * obstacle->getProperties().elasticCoefficient);
        m_properties.speed.ySpeed = (std::abs(ySpeed) == 1) ? 0 : ySpeed;
    }
}
