//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_COLLISIONPRONEMONSTER_H
#define FLASH_COLLISIONPRONEMONSTER_H

#include "Monster.h"
#include "../../../shared/collision/CollisionStrategy.h"
#include "../../../shared/collision/ObstacleCollision.h"
#include "../../../shared/collision/Collision.h"

namespace Mobs {

    class CollisionProneMonster : public Monster {
    public:
        explicit CollisionProneMonster(const std::shared_ptr<Components::ISpriteBox> &sprite,
                                       const std::shared_ptr<Material::Collision> &mobCollision)
                : Monster(sprite), _collision(mobCollision) {}

        explicit CollisionProneMonster(const std::shared_ptr<Components::ISpriteBox> &sprite,
                                       Material::Collision *mobCollision)
                : Monster(sprite), _collision(mobCollision) {}

    protected:
        std::shared_ptr<Material::Collision> _collision;
    };
}

#endif //FLASH_COLLISIONPRONEMONSTER_H
