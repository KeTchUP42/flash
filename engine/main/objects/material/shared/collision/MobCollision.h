//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_MOBCOLLISION_H
#define FLASH_MOBCOLLISION_H

#include "CollisionStrategy.h"

namespace Material {

    class MobCollision : public CollisionStrategy<Material::MaterialObject *, Material::MaterialObject *> {
    public:
        explicit MobCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY);

        Material::MaterialObject *abscissaMoveAble(Material::MaterialObject *object) const noexcept override;

        Material::MaterialObject *ordinateMoveAble(Material::MaterialObject *object) const noexcept override;

        void setAnalysisStepX(float analysisStepX) noexcept;

        void setAnalysisStepY(float analysisStepY) noexcept;

    protected:
        float ANALYSIS_STEP_X;
        float ANALYSIS_STEP_Y;
    };
}


#endif //FLASH_MOBCOLLISION_H
