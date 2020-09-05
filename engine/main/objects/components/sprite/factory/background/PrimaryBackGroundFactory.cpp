//
// Created by roman on 31.08.2020.
//

#include "PrimaryBackGroundFactory.h"
#include "../../composite/CompositeSpriteBox.h"
#include "../../sprite-box/SpriteBox.h"

std::shared_ptr<Components::ISpriteBox>
Components::PrimaryBackGroundFactory::createSpriteBox(Managers::DataManager *dataManager, const Components::Size &size) const {
    using namespace Components;
    CompositeSpriteBox *spriteBox = new CompositeSpriteBox();
    auto texture = dataManager->getTextureManager()->load("background/dungeon_back_1.jpg");
    //texture->setSmooth(true); //Resource-intensive option.
    spriteBox->addSpriteBox(new SpriteBox(Point(0, 0), size, texture));
    return std::shared_ptr<Components::ISpriteBox>(spriteBox);
}
