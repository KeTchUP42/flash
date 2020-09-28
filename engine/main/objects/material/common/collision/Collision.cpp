//
// Created by roman on 18.09.2020.
//

#include "Collision.h"

Material::Collision::Collision(float analysisStepX, float analysisStepY)
        : m_playerCollision(new Material::PlayerCollision(analysisStepX, analysisStepY)),
          m_monsterCollision(new Material::MonsterCollision(analysisStepX, analysisStepY)),
          m_obstacleCollision(new Material::ObstacleCollision(analysisStepX, analysisStepY)),
          m_staticPlayerCollision(new Material::StaticPlayerCollision()),
          m_staticMonsterCollision(new Material::StaticMonsterCollision()),
          m_staticObstacleCollision(new Material::StaticObstacleCollision()) {}

Material::MaterialObject *Material::Collision::abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Material::MaterialObject *result;

    if ((result = m_obstacleCollision->abscissaMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_monsterCollision->abscissaMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_playerCollision->abscissaMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_staticObstacleCollision->abscissaMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_staticMonsterCollision->abscissaMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_staticPlayerCollision->abscissaMoveAble(object, unifier)) != nullptr) {
        return result;
    }
    return nullptr;
}

Material::MaterialObject *Material::Collision::ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Material::MaterialObject *result;

    if ((result = m_obstacleCollision->ordinateMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_monsterCollision->ordinateMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_playerCollision->ordinateMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_staticObstacleCollision->ordinateMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_staticMonsterCollision->ordinateMoveAble(object, unifier)) != nullptr) {
        return result;
    }

    if ((result = m_staticPlayerCollision->ordinateMoveAble(object, unifier)) != nullptr) {
        return result;
    }
    return nullptr;
}

Mobs::Player *Material::Collision::abscissaPlayerMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Mobs::Player *player;

    if ((player = m_playerCollision->abscissaMoveAble(object, unifier)) != nullptr) {
        return player;
    }

    if ((player = m_staticPlayerCollision->abscissaMoveAble(object, unifier)) != nullptr) {
        return player;
    }
    return nullptr;
}

Mobs::Player *Material::Collision::ordinatePlayerMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Mobs::Player *player;

    if ((player = m_playerCollision->ordinateMoveAble(object, unifier)) != nullptr) {
        return player;
    }

    if ((player = m_staticPlayerCollision->ordinateMoveAble(object, unifier)) != nullptr) {
        return player;
    }
    return nullptr;
}


Mobs::Monster *Material::Collision::abscissaMonsterMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Mobs::Monster *monster;

    if ((monster = m_monsterCollision->abscissaMoveAble(object, unifier)) != nullptr) {
        return monster;
    }

    if ((monster = m_staticMonsterCollision->abscissaMoveAble(object, unifier)) != nullptr) {
        return monster;
    }
    return nullptr;
}

Mobs::Monster *Material::Collision::ordinateMonsterMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Mobs::Monster *monster;

    if ((monster = m_monsterCollision->ordinateMoveAble(object, unifier)) != nullptr) {
        return monster;
    }

    if ((monster = m_staticMonsterCollision->ordinateMoveAble(object, unifier)) != nullptr) {
        return monster;
    }
    return nullptr;
}

Obstacles::Obstacle *Material::Collision::abscissaObstacleMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Obstacles::Obstacle *obstacle;

    if ((obstacle = m_obstacleCollision->abscissaMoveAble(object, unifier)) != nullptr) {
        return obstacle;
    }

    if ((obstacle = m_staticObstacleCollision->abscissaMoveAble(object, unifier)) != nullptr) {
        return obstacle;
    }
    return nullptr;
}

Obstacles::Obstacle *Material::Collision::ordinateObstacleMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept {
    Obstacles::Obstacle *obstacle;

    if ((obstacle = m_obstacleCollision->ordinateMoveAble(object, unifier)) != nullptr) {
        return obstacle;
    }

    if ((obstacle = m_staticObstacleCollision->ordinateMoveAble(object, unifier)) != nullptr) {
        return obstacle;
    }
    return nullptr;
}

void Material::Collision::setAnalysisStepX(float analysisStepX) noexcept {
    m_playerCollision->setAnalysisStepX(analysisStepX);
    m_monsterCollision->setAnalysisStepX(analysisStepX);
    m_obstacleCollision->setAnalysisStepX(analysisStepX);
}

void Material::Collision::setAnalysisStepY(float analysisStepY) noexcept {
    m_playerCollision->setAnalysisStepY(analysisStepY);
    m_monsterCollision->setAnalysisStepY(analysisStepY);
    m_obstacleCollision->setAnalysisStepY(analysisStepY);
}

const std::shared_ptr<Material::PlayerCollision> &Material::Collision::getPlayerCollision() const noexcept {
    return m_playerCollision;
}

const std::shared_ptr<Material::MonsterCollision> &Material::Collision::getMonsterCollision() const noexcept {
    return m_monsterCollision;
}

const std::shared_ptr<Material::ObstacleCollision> &Material::Collision::getObstacleCollision() const noexcept {
    return m_obstacleCollision;
}

const std::shared_ptr<Material::StaticObstacleCollision> &Material::Collision::getStaticObstacleCollision() const noexcept {
    return m_staticObstacleCollision;
}

const std::shared_ptr<Material::StaticPlayerCollision> &Material::Collision::getStaticPlayerCollision() const noexcept {
    return m_staticPlayerCollision;
}

const std::shared_ptr<Material::StaticMonsterCollision> &Material::Collision::getStaticMonsterCollision() const noexcept {
    return m_staticMonsterCollision;
}
