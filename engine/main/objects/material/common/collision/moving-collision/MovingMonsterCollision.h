//
// Created by roman on 19.09.2020.
//

#ifndef FLASH_MOVINGMONSTERCOLLISION_H
#define FLASH_MOVINGMONSTERCOLLISION_H

#include "../CollisionStrategy.h"
#include "../../MaterialObject.h"
#include "MovingCollision.h"

namespace Material {

    class MovingMonsterCollision : public MovingCollision, public CollisionStrategy<Material::MaterialObject *, Mobs::Monster *> {
    public:
        explicit MovingMonsterCollision(float analysisStepX, float analysisStepY);

        Mobs::Monster *abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept override;

        Mobs::Monster *ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept override;
    };
}

#endif //FLASH_MOVINGMONSTERCOLLISION_H
