//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_BASEMONSTER_H
#define FLASH_BASEMONSTER_H

#include "Monster.h"
#include "../../../shared/collision/CollisionStrategy.h"
#include "../../../shared/collision/ObstacleCollision.h"
#include "../../../shared/collision/Collision.h"

namespace Mobs {

    class BaseMonster : public Monster {
    public:
        explicit BaseMonster(const std::shared_ptr<Components::ISpriteBox> &sprite,
                             const std::shared_ptr<Material::Collision> &mobCollision)
                : Monster(sprite), _collision(mobCollision) {}

        explicit BaseMonster(const std::shared_ptr<Components::ISpriteBox> &sprite,
                             Material::Collision *mobCollision)
                : Monster(sprite), _collision(mobCollision) {}

    protected:
        std::shared_ptr<Material::Collision> _collision;
    };
}

#endif //FLASH_BASEMONSTER_H
