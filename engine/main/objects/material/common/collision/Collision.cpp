//
// Created by roman on 18.09.2020.
//

#include "Collision.h"

Material::Collision::Collision(float analysisStepX, float analysisStepY)
        : m_movingPlayerCollision(analysisStepX, analysisStepY),
          m_movingMonsterCollision(analysisStepX, analysisStepY),
          m_movingObstacleCollision(analysisStepX, analysisStepY),
          m_staticPlayerCollision(),
          m_staticMonsterCollision(),
          m_staticObstacleCollision() {}

Material::MaterialObject *
Material::Collision::abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Material::MaterialObject *result;

    if ((result = m_movingObstacleCollision.abscissaMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_movingMonsterCollision.abscissaMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_movingPlayerCollision.abscissaMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_staticObstacleCollision.abscissaMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_staticMonsterCollision.abscissaMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_staticPlayerCollision.abscissaMoveAble(object, unifier)) != nullptr) {
        return result;
    }
    return nullptr;
}

Material::MaterialObject *
Material::Collision::ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Material::MaterialObject *result;

    if ((result = m_movingObstacleCollision.ordinateMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_movingMonsterCollision.ordinateMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_movingPlayerCollision.ordinateMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_staticObstacleCollision.ordinateMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_staticMonsterCollision.ordinateMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_staticPlayerCollision.ordinateMoveAble(object, unifier)) != nullptr) {
        return result;
    }
    return nullptr;
}

Mobs::Player *
Material::Collision::abscissaPlayerMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Mobs::Player *player;

    if ((player = m_movingPlayerCollision.abscissaMoveAble(object, unifier)) != nullptr) {
        return player;
    }

    if ((player = m_staticPlayerCollision.abscissaMoveAble(object, unifier)) != nullptr) {
        return player;
    }
    return nullptr;
}

Mobs::Player *
Material::Collision::ordinatePlayerMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Mobs::Player *player;

    if ((player = m_movingPlayerCollision.ordinateMoveAble(object, unifier)) != nullptr) {
        return player;
    }

    if ((player = m_staticPlayerCollision.ordinateMoveAble(object, unifier)) != nullptr) {
        return player;
    }
    return nullptr;
}


Mobs::Monster *
Material::Collision::abscissaMonsterMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Mobs::Monster *monster;

    if ((monster = m_movingMonsterCollision.abscissaMoveAble(object, unifier)) != nullptr) {
        return monster;
    }

    if ((monster = m_staticMonsterCollision.abscissaMoveAble(object, unifier)) != nullptr) {
        return monster;
    }
    return nullptr;
}

Mobs::Monster *
Material::Collision::ordinateMonsterMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Mobs::Monster *monster;

    if ((monster = m_movingMonsterCollision.ordinateMoveAble(object, unifier)) != nullptr) {
        return monster;
    }

    if ((monster = m_staticMonsterCollision.ordinateMoveAble(object, unifier)) != nullptr) {
        return monster;
    }
    return nullptr;
}

Obstacles::Obstacle *
Material::Collision::abscissaObstacleMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Obstacles::Obstacle *obstacle;

    if ((obstacle = m_movingObstacleCollision.abscissaMoveAble(object, unifier)) != nullptr) {
        return obstacle;
    }

    if ((obstacle = m_staticObstacleCollision.abscissaMoveAble(object, unifier)) != nullptr) {
        return obstacle;
    }
    return nullptr;
}

Obstacles::Obstacle *
Material::Collision::ordinateObstacleMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Obstacles::Obstacle *obstacle;

    if ((obstacle = m_movingObstacleCollision.ordinateMoveAble(object, unifier)) != nullptr) {
        return obstacle;
    }

    if ((obstacle = m_staticObstacleCollision.ordinateMoveAble(object, unifier)) != nullptr) {
        return obstacle;
    }
    return nullptr;
}

void Material::Collision::setAnalysisStepX(float analysisStepX) noexcept {
    m_movingPlayerCollision.setAnalysisStepX(analysisStepX);
    m_movingMonsterCollision.setAnalysisStepX(analysisStepX);
    m_movingObstacleCollision.setAnalysisStepX(analysisStepX);
}

void Material::Collision::setAnalysisStepY(float analysisStepY) noexcept {
    m_movingPlayerCollision.setAnalysisStepY(analysisStepY);
    m_movingMonsterCollision.setAnalysisStepY(analysisStepY);
    m_movingObstacleCollision.setAnalysisStepY(analysisStepY);
}

const Material::MovingPlayerCollision &Material::Collision::getMovingPlayerCollision() const noexcept {
    return m_movingPlayerCollision;
}

const Material::MovingMonsterCollision &Material::Collision::getMovingMonsterCollision() const noexcept {
    return m_movingMonsterCollision;
}

const Material::MovingObstacleCollision &Material::Collision::getMovingObstacleCollision() const noexcept {
    return m_movingObstacleCollision;
}

const Material::StaticObstacleCollision &Material::Collision::getStaticObstacleCollision() const noexcept {
    return m_staticObstacleCollision;
}

const Material::StaticPlayerCollision &Material::Collision::getStaticPlayerCollision() const noexcept {
    return m_staticPlayerCollision;
}

const Material::StaticMonsterCollision &Material::Collision::getStaticMonsterCollision() const noexcept {
    return m_staticMonsterCollision;
}
