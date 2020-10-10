//
// Created by roman on 01.10.2020.
//

#include "BasicPlayerGenerator.h"
#include "../../../../material/common/algorithms/Algorithms.h"
#include "../../../../material/mobs/player/custom/basic/BasicPlayer.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"

Generate::BasicPlayerGenerator::BasicPlayerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::BasicPlayerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //point
    Components::Point point(std::stof(data.at("X")), std::stof(data.at("Y")));
    //size
    Components::Size size(std::atoi(data.at("WIDTH").c_str()), std::atoi(data.at("HEIGHT").c_str()));
    //angle
    float angle = std::stof(data.at("ANGLE"));
    //real area
    Components::Area area(point, size, angle);

    //sprite point
    Components::Point spritePoint(std::stof(data.at("SPRITE_X")), std::stof(data.at("SPRITE_Y")));
    //sprite size
    Components::Size spriteSize(std::atoi(data.at("SPRITE_WIDTH").c_str()), std::atoi(data.at("SPRITE_HEIGHT").c_str()));
    //sprite area
    Components::Area spriteArea(spritePoint, spriteSize, angle);

    //properties
    Components::Speed speed(std::stof(data.at("X_SPEED")), std::stof(data.at("Y_SPEED")));
    Mobs::PlayerProperties properties(speed);

    //player properties
    Mobs::BasicPlayerProperties playerProperties(std::stof(data.at("MOVE_SPEED")), std::stof(data.at("MAX_MOVE_SPEED")),
                                                 std::stof(data.at("JUMP_SPEED")));

    //texture
    auto texture = m_source.getTexture(data.at("TEXTURE"));

    //algorithms
    std::pair<float, float> collisionParams = std::make_pair<float, float>(std::stof(data.at("COLLISION_ANALYSIS_STEP")),
                                                                           std::stof(data.at("COLLISION_ANALYSIS_STEP")));

    std::shared_ptr<Material::Algorithms> algorithms(
            new Material::Algorithms(m_source.getAlgpool()->loadCollision(collisionParams)));

    Mobs::Player *player = new Mobs::BasicPlayer(
            properties, area,
            std::shared_ptr<Components::ISpriteBox>(
                    new Components::SpriteBox(spriteArea, texture)), algorithms, playerProperties);

    player->loadKeyMap(data.at("KEYMAP"), m_source.getManager());
    unifier.addPlayer(player);
}
