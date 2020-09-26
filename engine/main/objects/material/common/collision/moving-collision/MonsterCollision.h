//
// Created by roman on 19.09.2020.
//

#ifndef FLASH_MONSTERCOLLISION_H
#define FLASH_MONSTERCOLLISION_H

#include "../CollisionStrategy.h"
#include "../../MaterialObject.h"
#include "MovingCollision.h"

namespace Material {

    class MonsterCollision : public MovingCollision, public CollisionStrategy<Material::MaterialObject *, Mobs::Monster *> {
    public:
        explicit MonsterCollision(float analysisStepX, float analysisStepY);

        Mobs::Monster *abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept override;

        Mobs::Monster *ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept override;
    };
}

#endif //FLASH_MONSTERCOLLISION_H
