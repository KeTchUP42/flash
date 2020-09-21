//
// Created by roman on 21.09.2020.
//

#ifndef FLASH_STATICPLAYERCOLLISION_H
#define FLASH_STATICPLAYERCOLLISION_H

#include "../CollisionStrategy.h"

namespace Material {

    class StaticPlayerCollision : public CollisionStrategy<Material::MaterialObject *, Mobs::Player *> {
    public:
        StaticPlayerCollision(Unite::Unifier *unifier);

        Mobs::Player *abscissaMoveAble(MaterialObject *object) const noexcept override;

        Mobs::Player *ordinateMoveAble(MaterialObject *object) const noexcept override;
    };
}

#endif //FLASH_STATICPLAYERCOLLISION_H
