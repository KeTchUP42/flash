//
// Created by roman on 10.09.2020.
//

#include "StartLevelFactory.h"
#include "../../unifier/CommonUnifier.h"
#include "../../mobs/player/custom/CommonPlayer.h"
#include "../../auxiliary/components/sprite/common/box/SpriteBox.h"

#include <memory>
#include <map>

std::shared_ptr<Unite::Unifier>
LevelGenerating::StartLevelFactory::loadLevel(const sf::Vector2u &size, Screen::StateChangeable *context,
                                              Managers::DataManager *manager) const {
    using namespace Unite;
    using namespace Mobs;
    using namespace Components;

    Unifier *unifier = new CommonUnifier(context);
    Player *player =
            new CommonPlayer(std::shared_ptr<ISpriteBox>(
                    new SpriteBox(
                            Point(600, 600),
                            Size(70, 50),
                            manager->getTextureManager()->load("mobs/player/mush.png"))));

    player->loadKeyMap("keys/keymap.ini", manager);
    unifier->addPlayer(player);

    return std::shared_ptr<Unite::Unifier>(unifier);
}