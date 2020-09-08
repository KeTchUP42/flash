//
// Created by roman on 06.09.2020.
//

#include "StoneWallSpriteFactory.h"
#include "../../../auxiliary/components/sprite/composite/CompositeSprite.h"
#include "../../../auxiliary/components/sprite/common/box/SpriteBox.h"

std::shared_ptr<Components::ISprite>
ComponentsGenerating::StoneWallSpriteFactory::createSprite(const Components::Point &point, const Components::Size &size,
                                                           Managers::DataManager *dataManager) const {
    using namespace Components;
    CompositeSprite *sprite = new CompositeSprite();
    auto texture = dataManager->getTextureManager()->load("structure/walls/stone/stone_wall_1.jpg");
    sprite->addSprite(new SpriteBox(point, size, texture));
    return std::shared_ptr<Components::ISprite>(sprite);
}
