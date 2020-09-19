//
// Created by roman on 19.09.2020.
//

#ifndef FLASH_PLAYERCOLLISION_H
#define FLASH_PLAYERCOLLISION_H

#include "CollisionStrategy.h"
#include "../MaterialObject.h"

namespace Material {

    class PlayerCollision : public CollisionStrategy<Material::MaterialObject *, Mobs::Player *> {
    public:
        explicit PlayerCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY);

        Mobs::Player *abscissaMoveAble(Material::MaterialObject *object) const noexcept override;

        Mobs::Player *ordinateMoveAble(Material::MaterialObject *object) const noexcept override;

        void setAnalysisStepX(float analysisStepX) noexcept;

        void setAnalysisStepY(float analysisStepY) noexcept;

    protected:
        float ANALYSIS_STEP_X;
        float ANALYSIS_STEP_Y;
    };
}

#endif //FLASH_PLAYERCOLLISION_H
