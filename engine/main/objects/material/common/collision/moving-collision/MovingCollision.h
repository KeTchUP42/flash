//
// Created by roman on 19.09.2020.
//

#ifndef FLASH_MOVINGCOLLISION_H
#define FLASH_MOVINGCOLLISION_H

namespace Material {

    class MovingCollision {
    public:
        MovingCollision(float analysisStepX, float analysisStepY);

        virtual void setAnalysisStepX(float analysisStepX) noexcept;

        virtual void setAnalysisStepY(float analysisStepY) noexcept;

    protected:
        float ANALYSIS_STEP_X;
        float ANALYSIS_STEP_Y;
    };
}

#endif //FLASH_MOVINGCOLLISION_H
