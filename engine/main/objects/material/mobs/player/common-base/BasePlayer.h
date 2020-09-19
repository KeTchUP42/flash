//
// Created by roman on 19.09.2020.
//

#ifndef FLASH_BASEPLAYER_H
#define FLASH_BASEPLAYER_H

#include "Player.h"
#include "../../../shared/collision/Collision.h"

namespace Mobs {

    class BasePlayer : public Player {
    public:
        explicit BasePlayer(const std::shared_ptr<Components::ISpriteBox> &sprite,
                            const std::shared_ptr<Material::Collision> &collision)
                : Player(sprite), _collision(collision) {}

        explicit BasePlayer(const std::shared_ptr<Components::ISpriteBox> &sprite,
                            Material::Collision *collision)
                : Player(sprite), _collision(collision) {}

    protected:
        std::shared_ptr<Material::Collision> _collision;
    };
}

#endif //FLASH_BASEPLAYER_H
