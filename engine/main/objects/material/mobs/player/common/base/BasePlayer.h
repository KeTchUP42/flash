//
// Created by roman on 19.09.2020.
//

#ifndef FLASH_BASEPLAYER_H
#define FLASH_BASEPLAYER_H

#include "Player.h"
#include "../../../../common/algorithms/Algorithms.h"

namespace Mobs {

    class BasePlayer : public Player {
    public:
        explicit BasePlayer(const Mobs::PlayerProperties &properties, const Components::Area &area,
                            const std::shared_ptr<Components::ISpriteBox> &sprite, const std::shared_ptr<Material::Algorithms> &algorithms)
                : Player(properties, area, sprite), m_algorithms(algorithms) {}

    protected:
        std::shared_ptr<Material::Algorithms> m_algorithms;
    };
}

#endif //FLASH_BASEPLAYER_H
