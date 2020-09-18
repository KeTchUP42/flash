//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_MUSHROOM_H
#define FLASH_MUSHROOM_H

#include "../../../../obstacles/shared/Obstacle.h"
#include "../../common-base/CollisionProneMonster.h"

namespace Mobs {

    class Mushroom : public CollisionProneMonster<Obstacles::Obstacle *> {
    public:
        explicit Mushroom(const std::shared_ptr<Components::ISpriteBox> &sprite,
                          const std::shared_ptr<CollisionStrategy<Obstacles::Obstacle *>> &collision);

        explicit Mushroom(const std::shared_ptr<Components::ISpriteBox> &sprite,
                          CollisionStrategy<Obstacles::Obstacle *> *collision);

        void selfAction(Unite::Unifier *unifier) override;

        void selfMove(Unite::Unifier *unifier) override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;
    };
}

#endif //FLASH_MUSHROOM_H
