//
// Created by roman on 10.09.2020.
//

#include "StartLevelFactory.h"
#include "../../unifier/CommonUnifier.h"
#include "../../mobs/player/custom/CommonPlayer.h"
#include "../../auxiliary/components/sprite/common/box/SpriteBox.h"
#include "../../static/effects/GravityEffect.h"

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
                            Size(50, 50),
                            manager->getTextureManager()->load("mobs/player/mush.png", sf::IntRect(170, 50, 530, 500)))));

    player->loadKeyMap("keys/keymap.ini", manager);
    unifier->addPlayer(player);

    unifier->addEffect(new Effects::GravityEffect(0.6));

    return std::shared_ptr<Unite::Unifier>(unifier);
}