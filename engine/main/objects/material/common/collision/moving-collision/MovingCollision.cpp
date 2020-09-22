//
// Created by roman on 19.09.2020.
//

#include "MovingCollision.h"

Material::MovingCollision::MovingCollision(float analysisStepX, float analysisStepY)
        : ANALYSIS_STEP_X(analysisStepX), ANALYSIS_STEP_Y(analysisStepY) {}

void Material::MovingCollision::setAnalysisStepX(float analysisStepX) noexcept {
    ANALYSIS_STEP_X = analysisStepX;
}

void Material::MovingCollision::setAnalysisStepY(float analysisStepY) noexcept {
    ANALYSIS_STEP_Y = analysisStepY;
}
