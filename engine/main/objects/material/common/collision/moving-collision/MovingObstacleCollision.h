//
// Created by roman on 12.09.2020.
//

#ifndef FLASH_MOVINGOBSTACLECOLLISION_H
#define FLASH_MOVINGOBSTACLECOLLISION_H

#include "../CollisionStrategy.h"
#include "MovingCollision.h"

namespace Material {

    class MovingObstacleCollision : public MovingCollision, public CollisionStrategy<Material::MaterialObject *, Obstacles::Obstacle *> {
    public:
        explicit MovingObstacleCollision(float analysisStepX, float analysisStepY);

        Obstacles::Obstacle *abscissaMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept override;

        Obstacles::Obstacle *ordinateMoveAble(Material::MaterialObject *object, Unite::Unifier *unifier) const noexcept override;
    };
}

#endif //FLASH_MOVINGOBSTACLECOLLISION_H
