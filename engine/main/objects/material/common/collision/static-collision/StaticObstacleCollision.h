//
// Created by roman on 20.09.2020.
//

#ifndef FLASH_STATICOBSTACLECOLLISION_H
#define FLASH_STATICOBSTACLECOLLISION_H

#include "../CollisionStrategy.h"

namespace Material {

    class StaticObstacleCollision : public CollisionStrategy<Material::MaterialObject *, Obstacles::Obstacle *> {
    public:
        Obstacles::Obstacle *abscissaMoveAble(MaterialObject *object, Unite::Unifier *unifier) const noexcept override;

        Obstacles::Obstacle *ordinateMoveAble(MaterialObject *object, Unite::Unifier *unifier) const noexcept override;
    };
}

#endif //FLASH_STATICOBSTACLECOLLISION_H
