//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_ELASTICBLOCK_H
#define FLASH_ELASTICBLOCK_H

#include "common-base/SingleSpriteBlock.h"

namespace Obstacles {

    class ElasticBlock : public Obstacles::SingleSpriteBlock {
    public:
        explicit ElasticBlock(const ObstacleProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                              const std::shared_ptr<Material::Algorithms> &algorithms);

        void selfAction(Unite::Unifier *unifier) override;

        void selfMove(Unite::Unifier *unifier) override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;
    };
}

#endif //FLASH_ELASTICBLOCK_H
