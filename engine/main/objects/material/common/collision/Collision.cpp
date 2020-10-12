//
// Created by roman on 18.09.2020.
//

#include "Collision.h"

Material::Collision::Collision(float analysisStepX, float analysisStepY)
        : m_movingCollision(analysisStepX, analysisStepY), m_staticCollision() {}

void Material::Collision::setAnalysisStepX(float analysisStepX) noexcept {
    m_movingCollision.setAnalysisStepX(analysisStepX);
}

void Material::Collision::setAnalysisStepY(float analysisStepY) noexcept {
    m_movingCollision.setAnalysisStepY(analysisStepY);
}

const Material::MovingCollision &Material::Collision::getMovingCollision() const noexcept {
    return m_movingCollision;
}

const Material::StaticCollision &Material::Collision::getStaticCollision() const noexcept {
    return m_staticCollision;
}
