//
// Created by roman on 12.09.2020.
//

#ifndef FLASH_OBSTACLECOLLISION_H
#define FLASH_OBSTACLECOLLISION_H

#include "CollisionStrategy.h"

namespace Material {

    class ObstacleCollision : public CollisionStrategy<Material::MaterialObject *, Obstacles::Obstacle *> {
    public:
        explicit ObstacleCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY);

        Obstacles::Obstacle *abscissaMoveAble(Material::MaterialObject *object) const noexcept override;

        Obstacles::Obstacle *ordinateMoveAble(Material::MaterialObject *object) const noexcept override;

        void setAnalysisStepX(float analysisStepX) noexcept;

        void setAnalysisStepY(float analysisStepY) noexcept;

    protected:
        float ANALYSIS_STEP_X;
        float ANALYSIS_STEP_Y;
    };
}

#endif //FLASH_OBSTACLECOLLISION_H
