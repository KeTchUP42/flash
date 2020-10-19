//
// Created by roman on 17.09.2020.
//

#include "Mushroom.h"

Mobs::Mushroom::Mushroom(const Mobs::MobProperties &properties, const Components::Area &area,
                         const std::shared_ptr<Components::ISpriteBox> &sprite,
                         const std::shared_ptr<Material::Algorithms> &algorithms, const Mobs::MushroomProperties &params)
        : BaseMob(properties, area, sprite, algorithms), m_mind(this), m_mushroom(params) {}

void Mobs::Mushroom::selfAction(Unite::Unifier *unifier) {
    m_mind.analyze(unifier);
}

void Mobs::Mushroom::selfMove(Unite::Unifier *unifier) {
    if (m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getObstacles()) != nullptr) {
        m_properties.speed.xSpeed = static_cast<int>(-1 * m_properties.speed.xSpeed);
    }

    Obstacles::Obstacle *obstacle;
    if ((obstacle = m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(this, unifier->getObstacles())) != nullptr) {
        bool sameSign = m_properties.speed.ySpeed * obstacle->getSpeed().ySpeed >= 0;
        float ySpeed = static_cast<int>(-1 * m_properties.speed.ySpeed * obstacle->getProperties().elasticCoefficient +
                                        (sameSign ? 0 : obstacle->getSpeed().ySpeed));
        m_properties.speed.ySpeed = (std::abs(ySpeed) == 1) ? 0 : ySpeed;
    }
}
