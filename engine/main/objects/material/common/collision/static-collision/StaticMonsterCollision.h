//
// Created by roman on 21.09.2020.
//

#ifndef FLASH_STATICMONSTERCOLLISION_H
#define FLASH_STATICMONSTERCOLLISION_H

#include "../CollisionStrategy.h"

namespace Material {

    class StaticMonsterCollision : public CollisionStrategy<Material::MaterialObject *, Mobs::Monster *> {
    public:
        Mobs::Monster *abscissaMoveAble(MaterialObject *object, Unite::Unifier *unifier) const noexcept override;

        Mobs::Monster *ordinateMoveAble(MaterialObject *object, Unite::Unifier *unifier) const noexcept override;
    };
}

#endif //FLASH_STATICMONSTERCOLLISION_H
