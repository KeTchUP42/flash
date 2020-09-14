//
// Created by roman on 10.09.2020.
//

#include "StartLevelFactory.h"
#include "../../unifier/GeneralUnifier.h"
#include "../../mobs/player/custom/BasicPlayer.h"
#include "../../auxiliary/components/sprite/common/box/SpriteBox.h"
#include "../../static/effects/GravityEffect.h"
#include "../../static/obstacles/blocks/single/DullBlock.h"
#include "../../mobs/shared/collision/BasicMobCollision.h"

#include <memory>
#include <map>

std::shared_ptr<Unite::Unifier>
LevelGenerating::StartLevelFactory::loadLevel(const sf::Vector2u &size, Screen::StateChangeable *context,
                                              Managers::DataManager *manager) const {
    using namespace Unite;
    using namespace Mobs;
    using namespace Components;
    Unifier *unifier = new GeneralUnifier(context);

    Player *player = new BasicPlayer(
            std::shared_ptr<ISpriteBox>(
                    new SpriteBox(
                            Point(600, 100),
                            Size(20, 20),  //10 - min
                            manager->getTextureManager()->loadTexture("mobs/player/mush.png"))),
            new BasicMobCollision(unifier, 3, 3));

    player->loadKeyMap("keys/keymap.ini", manager);
    unifier->addPlayer(player);

    unifier->addEffect(new Effects::GravityEffect(1));

    auto wall_texture = manager->getTextureManager()->loadTexture("structure/walls/stone/stone_wall_1.jpg");

    auto block = new Obstacles::DullBlock(
            std::shared_ptr<SpriteBox>(new SpriteBox(
                    Point(800, 340),
                    Size(150, 150),
                    wall_texture)));
    block->rotate(45);

    unifier->addObstacle(block);

    //
    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(175, 440),
                            Size(20, 20),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(175, 460),
                            Size(20, 20),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(175, 480),
                            Size(20, 20),
                            wall_texture))));
    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(175, 500),
                            Size(20, 20),
                            wall_texture))));
    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(175, 580),
                            Size(20, 20),
                            wall_texture))));
    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(175, 560),
                            Size(20, 20),
                            wall_texture))));
    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(175, 540),
                            Size(20, 20),
                            wall_texture))));
    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(175, 520),
                            Size(20, 20),
                            wall_texture))));
    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(175, 500),
                            Size(20, 20),
                            wall_texture))));
    //
    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(575, 400),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1200, 620),
                            Size(100, 100),
                            wall_texture))));


    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1100, 620),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1000, 620),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(900, 620),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(800, 620),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(700, 620),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(600, 620),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(500, 620),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(400, 620),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(300, 620),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(200, 620),
                            Size(100, 100),
                            wall_texture))));
    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(100, 620),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(0, 620),
                            Size(100, 100),
                            wall_texture))));

    return std::shared_ptr<Unite::Unifier>(unifier);
}