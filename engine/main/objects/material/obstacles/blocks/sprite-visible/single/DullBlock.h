//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_DULLBLOCK_H
#define FLASH_DULLBLOCK_H

#include "common-base/SingleSpriteBlock.h"

namespace Obstacles {

    class DullBlock : public Obstacles::SingleSpriteBlock {
    public:
        explicit DullBlock(const ObstacleProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                           const std::shared_ptr<Material::Algorithms> &algorithms);

        void selfAction(Unite::Unifier *unifier) override;
    };
}

#endif //FLASH_DULLBLOCK_H
