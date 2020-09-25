//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_MUSHROOM_H
#define FLASH_MUSHROOM_H

#include "../../../../obstacles/common/Obstacle.h"
#include "../../common-base/BaseMonster.h"

namespace Mobs {

    class Mushroom : public BaseMonster {
    public:
        explicit Mushroom(const Mobs::MonsterProperties &properties,
                          const std::shared_ptr<Components::ISpriteBox> &sprite,
                          const std::shared_ptr<Material::Collision> &collision);

        explicit Mushroom(const Mobs::MonsterProperties &properties,
                          const std::shared_ptr<Components::ISpriteBox> &sprite,
                          Material::Collision *collision);

        void selfAction(Unite::Unifier *unifier) override;

        void selfMove(Unite::Unifier *unifier) override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;
    };
}

#endif //FLASH_MUSHROOM_H
