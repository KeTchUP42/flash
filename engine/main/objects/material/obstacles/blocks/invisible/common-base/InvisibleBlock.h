//
// Created by roman on 06.10.2020.
//

#ifndef FLASH_INVISIBLEBLOCK_H
#define FLASH_INVISIBLEBLOCK_H

#include "../../common/AnalyzingBlock.h"

namespace Obstacles {

    class InvisibleBlock : public AnalyzingBlock {
    public:
        explicit InvisibleBlock(
                const ObstacleProperties &properties,
                const Components::Area &area,
                const std::shared_ptr<Material::Algorithms> &algorithms
        );

        void draw(sf::RenderTarget &target) const noexcept override;
    };
}

#endif //FLASH_INVISIBLEBLOCK_H
