//
// Created by roman on 20.09.2020.
//

#ifndef FLASH_STATICOBSTACLECOLLISION_H
#define FLASH_STATICOBSTACLECOLLISION_H

#include "../CollisionStrategy.h"

namespace Material {

    class StaticObstacleCollision : public CollisionStrategy<Material::MaterialObject *, Obstacles::Obstacle *> {
    public:
        StaticObstacleCollision(Unite::Unifier *unifier);

        Obstacles::Obstacle *abscissaMoveAble(MaterialObject *object) const noexcept override;

        Obstacles::Obstacle *ordinateMoveAble(MaterialObject *object) const noexcept override;
    };
}

#endif //FLASH_STATICOBSTACLECOLLISION_H
