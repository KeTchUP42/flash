//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_BASEMONSTER_H
#define FLASH_BASEMONSTER_H

#include "Monster.h"
#include "../../../common/collision/CollisionStrategy.h"
#include "../../../common/collision/moving-collision/ObstacleCollision.h"
#include "../../../common/collision/Collision.h"

namespace Mobs {

    class BaseMonster : public Monster {
    public:
        explicit BaseMonster(const Mobs::MonsterProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                             const std::shared_ptr<::Material::Collision> &collision)
                : Monster(properties, sprite), _collision(collision) {}

        explicit BaseMonster(const Mobs::MonsterProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                             Material::Collision *collision)
                : Monster(properties, sprite), _collision(collision) {}

    protected:
        std::shared_ptr<::Material::Collision> _collision;
    };
}

#endif //FLASH_BASEMONSTER_H
