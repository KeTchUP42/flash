//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_COLLISIONPRONEMONSTER_H
#define FLASH_COLLISIONPRONEMONSTER_H

#include "Monster.h"
#include "../../shared/collision/CollisionStrategy.h"

namespace Mobs {

    template<class CollisionTypeAnalisis>
    class CollisionProneMonster : public Monster {
    public:
        explicit CollisionProneMonster(const std::shared_ptr<Components::ISpriteBox> &sprite,
                                       const std::shared_ptr<CollisionStrategy<CollisionTypeAnalisis>> &collision)
                : _collision(collision), Mobs::Monster(sprite) {}

        explicit CollisionProneMonster(const std::shared_ptr<Components::ISpriteBox> &sprite,
                                       CollisionStrategy<CollisionTypeAnalisis> *collision)
                : _collision(collision), Mobs::Monster(sprite) {}

    protected:
        std::shared_ptr<CollisionStrategy<CollisionTypeAnalisis>> _collision;
    };
}

#endif //FLASH_COLLISIONPRONEMONSTER_H
