//
// Created by roman on 31.08.2020.
//

#include "PrimaryBackGroundFactory.h"
#include "../../../auxiliary/components/sprite/composite/CompositeSprite.h"
#include "../../../auxiliary/components/sprite/common/box/SpriteBox.h"

std::shared_ptr<Components::ISprite>
ComponentsGenerating::PrimaryBackGroundFactory::createSpriteBox(const sf::Vector2u &size,
                                                                Managers::DataManager *manager) const {
    using namespace Components;
    CompositeSprite *sprite = new CompositeSprite();
    auto texture = manager->getTextureManager()->loadTexture("background/dungeon_back_2.png");
    //texture->setSmooth(true); //Resource-intensive option.
    sprite->addSprite(new SpriteBox(Point(0, 0), Size(size.x, size.y), texture));
    return std::shared_ptr<Components::ISprite>(sprite);
}
