//
// Created by roman on 08.11.2020.
//

#ifndef FLASH_BASEBLOCK_H
#define FLASH_BASEBLOCK_H

#include "Block.h"
#include "../../../common/algorithms/Algorithms.h"

namespace Obstacles {

    class BaseBlock : public Block {
    public:
        explicit BaseBlock(const ObstacleProperties &properties, const Components::Area &area, const std::shared_ptr<Material::Algorithms> &algorithms)
                : Block(properties, area), m_algorithms(algorithms) {}

    protected:
        std::shared_ptr<Material::Algorithms> m_algorithms;
    };
}

#endif //FLASH_BASEBLOCK_H
