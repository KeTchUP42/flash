//
// Created by roman on 31.08.2020.
//

#include "PrimaryBackGroundFactory.h"
#include "../../composite/CompositeSprite.h"
#include "../../simple/box/SpriteBox.h"

std::shared_ptr<Components::ISprite>
Components::Factory::PrimaryBackGroundFactory::createSpriteBox(const Size &size, Managers::DataManager *dataManager) const {
    using namespace Components;
    CompositeSprite *sprite = new CompositeSprite();
    auto texture = dataManager->getTextureManager()->load("background/dungeon_back_1.jpg");
    //texture->setSmooth(true); //Resource-intensive option.
    sprite->addSprite(new SpriteBox(Point(0, 0), size, texture));
    return std::shared_ptr<Components::ISprite>(sprite);
}
