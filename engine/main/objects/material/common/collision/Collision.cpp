//
// Created by roman on 18.09.2020.
//

#include "Collision.h"

Material::Collision::Collision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY)
        : CollisionStrategy(unifier),
          _playerCollision(new Material::PlayerCollision(unifier, analysisStepX, analysisStepY)),
          _monsterCollision(new Material::MonsterCollision(unifier, analysisStepX, analysisStepY)),
          _obstacleCollision(new Material::ObstacleCollision(unifier, analysisStepX, analysisStepY)),
          _staticPlayerCollision(new Material::StaticPlayerCollision(unifier)),
          _staticMonsterCollision(new Material::StaticMonsterCollision(unifier)),
          _staticObstacleCollision(new Material::StaticObstacleCollision(unifier)) {}

Material::MaterialObject *Material::Collision::abscissaMoveAble(Material::MaterialObject *object) const noexcept {
    Material::MaterialObject *result;

    if ((result = _obstacleCollision->abscissaMoveAble(object)) != nullptr) {
        return result;
    }

    if ((result = _monsterCollision->abscissaMoveAble(object)) != nullptr) {
        return result;
    }

    if ((result = _playerCollision->abscissaMoveAble(object)) != nullptr) {
        return result;
    }

    if ((result = _staticObstacleCollision->abscissaMoveAble(object)) != nullptr) {
        return result;
    }

    if ((result = _staticMonsterCollision->abscissaMoveAble(object)) != nullptr) {
        return result;
    }

    if ((result = _staticPlayerCollision->abscissaMoveAble(object)) != nullptr) {
        return result;
    }
    return nullptr;
}

Material::MaterialObject *Material::Collision::ordinateMoveAble(Material::MaterialObject *object) const noexcept {
    Material::MaterialObject *result;

    if ((result = _obstacleCollision->ordinateMoveAble(object)) != nullptr) {
        return result;
    }

    if ((result = _monsterCollision->ordinateMoveAble(object)) != nullptr) {
        return result;
    }

    if ((result = _playerCollision->ordinateMoveAble(object)) != nullptr) {
        return result;
    }

    if ((result = _staticObstacleCollision->ordinateMoveAble(object)) != nullptr) {
        return result;
    }

    if ((result = _staticMonsterCollision->ordinateMoveAble(object)) != nullptr) {
        return result;
    }

    if ((result = _staticPlayerCollision->ordinateMoveAble(object)) != nullptr) {
        return result;
    }
    return nullptr;
}

Mobs::Player *Material::Collision::abscissaPlayerMoveAble(Material::MaterialObject *object) const noexcept {
    Mobs::Player *player;

    if ((player = _playerCollision->abscissaMoveAble(object)) != nullptr) {
        return player;
    }

    if ((player = _staticPlayerCollision->abscissaMoveAble(object)) != nullptr) {
        return player;
    }
    return nullptr;
}

Mobs::Player *Material::Collision::ordinatePlayerMoveAble(Material::MaterialObject *object) const noexcept {
    Mobs::Player *player;

    if ((player = _playerCollision->ordinateMoveAble(object)) != nullptr) {
        return player;
    }

    if ((player = _staticPlayerCollision->ordinateMoveAble(object)) != nullptr) {
        return player;
    }
    return nullptr;
}


Mobs::Monster *Material::Collision::abscissaMonsterMoveAble(Material::MaterialObject *object) const noexcept {
    Mobs::Monster *monster;

    if ((monster = _monsterCollision->abscissaMoveAble(object)) != nullptr) {
        return monster;
    }

    if ((monster = _staticMonsterCollision->abscissaMoveAble(object)) != nullptr) {
        return monster;
    }
    return nullptr;
}

Mobs::Monster *Material::Collision::ordinateMonsterMoveAble(Material::MaterialObject *object) const noexcept {
    Mobs::Monster *monster;

    if ((monster = _monsterCollision->ordinateMoveAble(object)) != nullptr) {
        return monster;
    }

    if ((monster = _staticMonsterCollision->ordinateMoveAble(object)) != nullptr) {
        return monster;
    }
    return nullptr;
}

Obstacles::Obstacle *Material::Collision::abscissaObstacleMoveAble(Material::MaterialObject *object) const noexcept {
    Obstacles::Obstacle *obstacle;

    if ((obstacle = _obstacleCollision->abscissaMoveAble(object)) != nullptr) {
        return obstacle;
    }

    if ((obstacle = _staticObstacleCollision->abscissaMoveAble(object)) != nullptr) {
        return obstacle;
    }
    return nullptr;
}

Obstacles::Obstacle *Material::Collision::ordinateObstacleMoveAble(Material::MaterialObject *object) const noexcept {
    Obstacles::Obstacle *obstacle;

    if ((obstacle = _obstacleCollision->ordinateMoveAble(object)) != nullptr) {
        return obstacle;
    }

    if ((obstacle = _staticObstacleCollision->ordinateMoveAble(object)) != nullptr) {
        return obstacle;
    }
    return nullptr;
}

void Material::Collision::setAnalysisStepX(float analysisStepX) noexcept {
    _playerCollision->setAnalysisStepX(analysisStepX);
    _monsterCollision->setAnalysisStepX(analysisStepX);
    _obstacleCollision->setAnalysisStepX(analysisStepX);
}

void Material::Collision::setAnalysisStepY(float analysisStepY) noexcept {
    _playerCollision->setAnalysisStepY(analysisStepY);
    _monsterCollision->setAnalysisStepY(analysisStepY);
    _obstacleCollision->setAnalysisStepY(analysisStepY);
}

const std::shared_ptr<Material::PlayerCollision> &Material::Collision::getPlayerCollision() const noexcept {
    return _playerCollision;
}

const std::shared_ptr<Material::MonsterCollision> &Material::Collision::getMonsterCollision() const noexcept {
    return _monsterCollision;
}

const std::shared_ptr<Material::ObstacleCollision> &Material::Collision::getObstacleCollision() const noexcept {
    return _obstacleCollision;
}

const std::shared_ptr<Material::StaticObstacleCollision> &Material::Collision::getStaticObstacleCollision() const noexcept {
    return _staticObstacleCollision;
}

const std::shared_ptr<Material::StaticPlayerCollision> &Material::Collision::getStaticPlayerCollision() const noexcept {
    return _staticPlayerCollision;
}

const std::shared_ptr<Material::StaticMonsterCollision> &Material::Collision::getStaticMonsterCollision() const noexcept {
    return _staticMonsterCollision;
}
