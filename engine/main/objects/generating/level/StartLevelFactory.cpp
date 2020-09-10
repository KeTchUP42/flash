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

    //In future load from file!
    std::map<KeyAlias, sf::Keyboard::Key> keys;
    keys[KeyAlias::Right] = sf::Keyboard::Key::D;
    keys[KeyAlias::Left] = sf::Keyboard::Key::A;
    keys[KeyAlias::Jump] = sf::Keyboard::Key::Space;
    player->loadKeyMap(keys);

    unifier->addPlayer(player);

    return std::shared_ptr<Unite::Unifier>(unifier);
}