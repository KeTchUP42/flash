//
// Created by roman on 19.09.2020.
//

#ifndef FLASH_MOVINGPLAYERCOLLISION_H
#define FLASH_MOVINGPLAYERCOLLISION_H

#include "../CollisionStrategy.h"
#include "../../MaterialObject.h"
#include "MovingCollision.h"

namespace Material {

    class MovingPlayerCollision : public MovingCollision, public CollisionStrategy<Material::MaterialObject *, Mobs::Player *> {
    public:
        explicit MovingPlayerCollision(float analysisStepX, float analysisStepY);

        Mobs::Player *abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept override;

        Mobs::Player *ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept override;
    };
}

#endif //FLASH_MOVINGPLAYERCOLLISION_H
