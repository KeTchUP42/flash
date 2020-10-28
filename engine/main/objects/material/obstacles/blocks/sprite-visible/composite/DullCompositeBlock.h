//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_DULLCOMPOSITEBLOCK_H
#define FLASH_DULLCOMPOSITEBLOCK_H

#include "common-base/CompositeSpriteBlock.h"

namespace Obstacles {

    class DullCompositeBlock : public CompositeSpriteBlock {
    public:
        DullCompositeBlock(const ObstacleProperties &properties, const Components::Area &area,
                           const std::shared_ptr<Components::ISprite> &sprite, const std::shared_ptr<Material::Algorithms> &algorithms);

        void selfAction(Unite::Unifier *unifier) override;
    };
}

#endif //FLASH_DULLCOMPOSITEBLOCK_H
