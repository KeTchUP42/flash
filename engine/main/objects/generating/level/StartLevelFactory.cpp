//
// Created by roman on 10.09.2020.
//

#include "StartLevelFactory.h"
#include "../../unifier/GeneralUnifier.h"
#include "../../material/mobs/player/custom/BasicPlayer.h"
#include "../../material/mobs/monsters/custom/mushroom/Mushroom.h"
#include "../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../../static/effects/GravityEffect.h"
#include "../../material/obstacles/blocks/single/DullBlock.h"
#include "../../static/triggers/area/PlainLevelTrigger.h"

#include <memory>
#include <map>

std::shared_ptr<Unite::Unifier>
Generating::StartLevelFactory::loadLevel(Screen::StateChangeable *context, Managers::DataManager *manager,
                                         sf::RenderWindow &target) const {
    using namespace Unite;
    using namespace Components;

    Unifier *unifier = new GeneralUnifier();
    StartLevelFactory::loadLevel(unifier, context, manager, target);

    unifier->addTrigger(new Triggers::PlainLevelTrigger(Area(Point(1000, 500), Size(100, 100), 0), context));//todo

    return std::shared_ptr<Unite::Unifier>(unifier);
}

void Generating::StartLevelFactory::
loadLevel(Unite::Unifier *unifier, Screen::StateChangeable *context,
          Managers::DataManager *manager, sf::RenderWindow &target) const {

    using namespace Unite;
    using namespace Mobs;
    using namespace Components;
    using namespace Material;

    std::shared_ptr<Collision> collision(new Collision(5, 5));
    std::shared_ptr<Algorithms> algorithms(new Algorithms(collision));


    unifier->addBackSprite(new SpriteBox(Point(0, 0), Size(target.getSize().x, target.getSize().y),
                                         manager->getTextureManager()->loadTexture("background/dungeon_back_1.jpg")));


    Player *player = new BasicPlayer(
            PlayerProperties(Speed(0, 0)),
            std::shared_ptr<ISpriteBox>(
                    new SpriteBox(
                            Point(610, 110),
                            Size(20, 20),  //10 - min
                            manager->getTextureManager()->loadTexture("mobs/player/mush.png"))),
            algorithms);

    player->loadKeyMap("keys/keymap.ini", manager);
    unifier->addPlayer(player);

    //mushroom

    auto mushroom = manager->getTextureManager()->loadTexture("mobs/monsters/mushroom/mushroom.png");

    unifier->addMonster(new Mobs::Mushroom(
            MonsterProperties(Speed(-1, 0)),
            std::shared_ptr<ISpriteBox>(
                    std::make_shared<SpriteBox>(
                            Point(555, 250),
                            Size(30, 30),  //10 - min
                            mushroom)), algorithms));

    unifier->addMonster(new Mobs::Mushroom(
            MonsterProperties(Speed(-1, 0)),
            std::shared_ptr<ISpriteBox>(
                    std::make_shared<SpriteBox>(
                            Point(1060, 280),
                            Size(30, 30),  //10 - min
                            mushroom)), algorithms));


    unifier->addMonster(new Mobs::Mushroom(
            MonsterProperties(Speed(1, 4)),
            std::shared_ptr<ISpriteBox>(
                    std::make_shared<SpriteBox>(
                            Point(1060, 320),
                            Size(30, 30),  //10 - min
                            mushroom)), algorithms));


    //gravity
    unifier->addEffect(new Effects::GravityEffect(0, 0.8));

    //walls
    Obstacles::ObstacleProperties properties(Speed(0, 0), 0.2, true);
    auto wall_texture = manager->getTextureManager()->loadTexture("structure/walls/stone/stone_wall_1.jpg");

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(1100, 300),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(100, 0),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(200, 0),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(300, 0),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(400, 0),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(500, 0),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(600, 0),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(700, 0),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(800, 0),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(900, 0),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(1000, 0),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(1100, 0),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(1200, 0),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(1200, 100),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(1200, 200),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(1200, 300),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(1200, 400),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(1200, 500),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(1200, 600),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(1100, 600),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(1000, 600),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(900, 600),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(800, 600),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(700, 600),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(600, 600),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(500, 600),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(400, 600),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(300, 600),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(200, 600),
                            Size(100, 100),
                            wall_texture), algorithms));
    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(100, 600),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(0, 600),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(0, 500),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(0, 400),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(0, 300),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(0, 200),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(0, 100),
                            Size(100, 100),
                            wall_texture), algorithms));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    properties,
                    std::make_shared<SpriteBox>(
                            Point(0, 0),
                            Size(100, 100),
                            wall_texture), algorithms));
}
