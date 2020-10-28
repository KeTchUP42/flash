//
// Created by roman on 06.10.2020.
//

#ifndef FLASH_PLATFORMBLOCK_H
#define FLASH_PLATFORMBLOCK_H

#include "common-base/SingleSpriteBlock.h"

namespace Obstacles {

    class PlatformBlock : public SingleSpriteBlock {
    public:
        explicit PlatformBlock(
                const ObstacleProperties &properties,
                const std::shared_ptr<Components::ISpriteBox> &sprite,
                const std::shared_ptr<Material::Algorithms> &algorithms
        );

        void selfAction(Unite::Unifier *unifier) override;
    };
}

#endif //FLASH_PLATFORMBLOCK_H
