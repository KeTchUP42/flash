//
// Created by roman on 12.09.2020.
//

#ifndef FLASH_BASICMOBCOLLISION_H
#define FLASH_BASICMOBCOLLISION_H

#include "CollisionStrategy.h"

namespace Mobs {

    class BasicMobCollision : public CollisionStrategy<std::shared_ptr<Obstacles::Obstacle>> {
    public:
        explicit BasicMobCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY);

        std::shared_ptr<Obstacles::Obstacle> abscissaMoveAble(Mob *mob) const noexcept override;

        std::shared_ptr<Obstacles::Obstacle> ordinateMoveAble(Mob *mob) const noexcept override;

        void setAnalysisStepX(float analysisStepX) noexcept;

        void setAnalysisStepY(float analysisStepY) noexcept;

    protected:
        float ANALYSIS_STEP_X;
        float ANALYSIS_STEP_Y;
    };
}

#endif //FLASH_BASICMOBCOLLISION_H
