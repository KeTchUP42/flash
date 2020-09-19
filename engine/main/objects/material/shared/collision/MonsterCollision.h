//
// Created by roman on 19.09.2020.
//

#ifndef FLASH_MONSTERCOLLISION_H
#define FLASH_MONSTERCOLLISION_H

#include "CollisionStrategy.h"
#include "../MaterialObject.h"

namespace Material {

    class MonsterCollision : public CollisionStrategy<Material::MaterialObject *, Material::MaterialObject *> {
    public:
        explicit MonsterCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY);

        Material::MaterialObject *abscissaMoveAble(Material::MaterialObject *object) const noexcept override;

        Material::MaterialObject *ordinateMoveAble(Material::MaterialObject *object) const noexcept override;

        void setAnalysisStepX(float analysisStepX) noexcept;

        void setAnalysisStepY(float analysisStepY) noexcept;

    protected:
        float ANALYSIS_STEP_X;
        float ANALYSIS_STEP_Y;
    };
}

#endif //FLASH_MONSTERCOLLISION_H
