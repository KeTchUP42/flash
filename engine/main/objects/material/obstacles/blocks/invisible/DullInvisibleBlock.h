//
// Created by roman on 06.10.2020.
//

#ifndef FLASH_DULLINVISIBLEBLOCK_H
#define FLASH_DULLINVISIBLEBLOCK_H

#include "common-base/InvisibleBlock.h"

namespace Obstacles {

    class DullInvisibleBlock : public InvisibleBlock {
    public:
        explicit DullInvisibleBlock(const ObstacleProperties &properties, const Components::Area &area,
                                    const std::shared_ptr<Material::Algorithms> &algorithms);

        void selfAction(Unite::Unifier *unifier) override;
    };
}

#endif //FLASH_DULLINVISIBLEBLOCK_H
