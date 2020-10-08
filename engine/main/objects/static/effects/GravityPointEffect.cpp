//
// Created by roman on 08.10.2020.
//

#include "GravityPointEffect.h"

Effects::GravityPointEffect::GravityPointEffect(const Components::Point &point, float acceleration)
        : m_point(point), ACCELERATION(acceleration) {}

void Effects::GravityPointEffect::applyEffect(Unite::Unifier *unifier) {
    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {

        float playerX = player->getPosition().x + player->getSize().width;
        if (playerX > m_point.x) {
            player->addSpeed(-ACCELERATION, 0);
        } else if (playerX < m_point.x) {
            player->addSpeed(ACCELERATION, 0);
        }

        float playerY = player->getPosition().y + player->getSize().height;
        if (playerY > m_point.y) {
            player->addSpeed(0, -ACCELERATION);
        } else if (playerY < m_point.y) {
            player->addSpeed(0, ACCELERATION);
        }
    }

    for (const std::shared_ptr<Mobs::Monster> &monster : unifier->getMonsters()) {

        float monsterX = monster->getPosition().x + monster->getSize().width;
        if (monsterX > m_point.x) {
            monster->addSpeed(-ACCELERATION, 0);
        } else if (monsterX < m_point.x) {
            monster->addSpeed(ACCELERATION, 0);
        }

        float monsterY = monster->getPosition().y + monster->getSize().height;
        if (monsterY > m_point.y) {
            monster->addSpeed(0, -ACCELERATION);
        } else if (monsterY < m_point.y) {
            monster->addSpeed(0, ACCELERATION);
        }
    }

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle : unifier->getObstacles()) {
        if (!obstacle->getProperties().isFixed) {

            float obstacleX = obstacle->getPosition().x + obstacle->getSize().width;
            if (obstacleX > m_point.x) {
                obstacle->addSpeed(-ACCELERATION, 0);
            } else if (obstacleX < m_point.x) {
                obstacle->addSpeed(ACCELERATION, 0);
            }

            float obstacleY = obstacle->getPosition().y + obstacle->getSize().height;
            if (obstacleY > m_point.y) {
                obstacle->addSpeed(0, -ACCELERATION);
            } else if (obstacleY < m_point.y) {
                obstacle->addSpeed(0, ACCELERATION);
            }
        }
    }
}

void Effects::GravityPointEffect::move(float offsetX, float offsetY) noexcept {
    m_point.x += offsetX;
    m_point.y += offsetY;
}

const Components::Point &Effects::GravityPointEffect::getPoint() const {
    return m_point;
}

void Effects::GravityPointEffect::setPoint(const Components::Point &point) noexcept {
    m_point = point;
}

