//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_COLLISIONPRONEMONSTER_H
#define FLASH_COLLISIONPRONEMONSTER_H

#include "Monster.h"
#include "../../../shared/collision/CollisionStrategy.h"
#include "../../../shared/collision/ObstacleCollision.h"
#include "../../../shared/collision/MobCollision.h"

namespace Mobs {

    class CollisionProneMonster : public Monster {
    public:
        explicit CollisionProneMonster(const std::shared_ptr<Components::ISpriteBox> &sprite,
                                       const std::shared_ptr<Material::ObstacleCollision> &obstacleCollision,
                                       const std::shared_ptr<Material::MobCollision> &mobCollision)
                : Monster(sprite), _obstacleCollision(obstacleCollision), _mobCollision(mobCollision) {}

        explicit CollisionProneMonster(const std::shared_ptr<Components::ISpriteBox> &sprite,
                                       Material::ObstacleCollision *obstacleCollision, Material::MobCollision *mobCollision)
                : Monster(sprite), _obstacleCollision(obstacleCollision), _mobCollision(mobCollision) {}

    protected:
        std::shared_ptr<Material::ObstacleCollision> _obstacleCollision;
        std::shared_ptr<Material::MobCollision> _mobCollision;
    };
}

#endif //FLASH_COLLISIONPRONEMONSTER_H
