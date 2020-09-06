//
// Created by roman on 06.09.2020.
//

#include "StoneWallSpriteFactory.h"
#include "../../composite/CompositeSpriteBox.h"
#include "../../sprite-box/SpriteBox.h"

std::shared_ptr<Components::ISpriteBox>
Components::Factory::StoneWallSpriteFactory::createSpriteBox(const Components::Point &point, const Components::Size &size,
                                                             Managers::DataManager *dataManager) const {
    using namespace Components;
    CompositeSpriteBox *spriteBox = new CompositeSpriteBox();
    auto texture = dataManager->getTextureManager()->load("structure/walls/stone/stone_wall_1.jpg");
    spriteBox->addSpriteBox(new SpriteBox(point, size, texture));
    return std::shared_ptr<Components::ISpriteBox>(spriteBox);
}
