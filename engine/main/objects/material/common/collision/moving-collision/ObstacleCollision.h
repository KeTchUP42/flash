//
// Created by roman on 12.09.2020.
//

#ifndef FLASH_OBSTACLECOLLISION_H
#define FLASH_OBSTACLECOLLISION_H

#include "../CollisionStrategy.h"
#include "MovingCollision.h"

namespace Material {

    class ObstacleCollision : public MovingCollision, public CollisionStrategy<Material::MaterialObject *, Obstacles::Obstacle *> {
    public:
        explicit ObstacleCollision(float analysisStepX, float analysisStepY);

        Obstacles::Obstacle *abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept override;

        Obstacles::Obstacle *ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept override;
    };
}

#endif //FLASH_OBSTACLECOLLISION_H
