//
// Created by roman on 19.09.2020.
//

#ifndef FLASH_PLAYERCOLLISION_H
#define FLASH_PLAYERCOLLISION_H

#include "../CollisionStrategy.h"
#include "../../MaterialObject.h"
#include "MovingCollision.h"

namespace Material {

    class PlayerCollision : public MovingCollision, public CollisionStrategy<Material::MaterialObject *, Mobs::Player *> {
    public:
        explicit PlayerCollision(Unite::Unifier *unifier, float analysisStepX, float analysisStepY);

        Mobs::Player *abscissaMoveAble(Material::MaterialObject *object) const noexcept override;

        Mobs::Player *ordinateMoveAble(Material::MaterialObject *object) const noexcept override;
    };
}

#endif //FLASH_PLAYERCOLLISION_H
