//
// Created by roman on 18.09.2020.
//

#include "Collision.h"

Material::Collision::Collision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY)
        : CollisionStrategy(unifier),
          _playerCollision(new Material::PlayerCollision(unifier, analysisStepX, analysisStepY)),
          _monsterCollision(new Material::MonsterCollision(unifier, analysisStepX, analysisStepY)),
          _obstacleCollision(new Material::ObstacleCollision(unifier, analysisStepX, analysisStepY)) {}

Material::MaterialObject *Material::Collision::abscissaMoveAble(Material::MaterialObject *object) const noexcept {
    Material::MaterialObject *rObject;

    if ((rObject = _obstacleCollision->abscissaMoveAble(object)) != nullptr) {
        return rObject;
    }

    if ((rObject = _monsterCollision->abscissaMoveAble(object)) != nullptr) {
        return rObject;
    }

    if ((rObject = _playerCollision->abscissaMoveAble(object)) != nullptr) {
        return rObject;
    }

    return nullptr;
}

Material::MaterialObject *Material::Collision::ordinateMoveAble(Material::MaterialObject *object) const noexcept {
    Material::MaterialObject *rObject;

    if ((rObject = _obstacleCollision->ordinateMoveAble(object)) != nullptr) {
        return rObject;
    }

    if ((rObject = _monsterCollision->ordinateMoveAble(object)) != nullptr) {
        return rObject;
    }

    if ((rObject = _playerCollision->ordinateMoveAble(object)) != nullptr) {
        return rObject;
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

const std::shared_ptr<Material::ObstacleCollision> &Material::Collision::getObstacleCollision() const {
    return _obstacleCollision;
}
