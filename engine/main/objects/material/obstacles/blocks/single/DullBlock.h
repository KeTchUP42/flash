//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_DULLBLOCK_H
#define FLASH_DULLBLOCK_H

#include "common-base/SingleSpriteBlock.h"

namespace Obstacles {

    class DullBlock : public Obstacles::SingleSpriteBlock {
    public:
        DullBlock(const ObstacleProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite);

        void selfAction(Unite::Unifier *unifier) override;

        void selfMove(Unite::Unifier *unifier) override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;
    };
}

#endif //FLASH_DULLBLOCK_H
