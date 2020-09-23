//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_DULLCOMPOSITEBLOCK_H
#define FLASH_DULLCOMPOSITEBLOCK_H

#include "common-base/CompositeSpriteBlock.h"

namespace Obstacles {

    class DullCompositeBlock : public CompositeSpriteBlock {
    public:
        DullCompositeBlock(const Components::Area &area, const ObstacleProperties &properties,
                           const std::shared_ptr<Components::ISprite> &sprite);

        void selfAction(Unite::Unifier *unifier) override;

        void selfMove(Unite::Unifier *unifier) override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;
    };
}


#endif //FLASH_DULLCOMPOSITEBLOCK_H
