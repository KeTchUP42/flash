//
// Created by roman on 18.09.2020.
//

#include "MobCollision.h"

Material::MobCollision::MobCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY)
        : CollisionStrategy(unifier),
          _monsterCollision(new Material::MonsterCollision(unifier, analysisStepX, analysisStepY)),
          _playerCollision(new Material::PlayerCollision(unifier, analysisStepX, analysisStepY)) {}

Material::MaterialObject *Material::MobCollision::abscissaMoveAble(Material::MaterialObject *object) const noexcept {
    Material::MaterialObject *mob;

    if ((mob = _playerCollision->abscissaMoveAble(object)) != nullptr) {
        return mob;
    }

    if ((mob = _monsterCollision->abscissaMoveAble(object)) != nullptr) {
        return mob;
    }

    return nullptr;
}

Material::MaterialObject *Material::MobCollision::ordinateMoveAble(Material::MaterialObject *object) const noexcept {
    Material::MaterialObject *mob;

    if ((mob = _playerCollision->ordinateMoveAble(object)) != nullptr) {
        return mob;
    }

    if ((mob = _monsterCollision->ordinateMoveAble(object)) != nullptr) {
        return mob;
    }

    return nullptr;
}

void Material::MobCollision::setAnalysisStepX(float analysisStepX) noexcept {
    _playerCollision->setAnalysisStepX(analysisStepX);
    _monsterCollision->setAnalysisStepX(analysisStepX);
}

void Material::MobCollision::setAnalysisStepY(float analysisStepY) noexcept {
    _playerCollision->setAnalysisStepY(analysisStepY);
    _monsterCollision->setAnalysisStepY(analysisStepY);
}

const std::shared_ptr<Material::PlayerCollision> &Material::MobCollision::getPlayerCollision() const noexcept {
    return _playerCollision;
}

const std::shared_ptr<Material::MonsterCollision> &Material::MobCollision::getMonsterCollision() const noexcept {
    return _monsterCollision;
}
