//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_ELASTICBLOCK_H
#define FLASH_ELASTICBLOCK_H

#include "common-base/SingleSpriteBlock.h"

namespace Obstacles {

    class ElasticBlock : public Obstacles::SingleSpriteBlock {
    public:
        explicit ElasticBlock(
                const Material::MaterialProperties &material_properties,
                const ObstacleProperties &properties,
                const std::shared_ptr<Components::ISpriteBox> &sprite,
                const std::shared_ptr<Material::Algorithms> &algorithms
        );

        void selfAction(Unite::Unifier *unifier) override;
    };
}

#endif //FLASH_ELASTICBLOCK_H
