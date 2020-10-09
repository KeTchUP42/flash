//
// Created by roman on 01.10.2020.
//

#include "MushroomGenerator.h"
#include "../../../../material/mobs/monsters/custom/mushroom/Mushroom.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"

Generate::MushroomGenerator::MushroomGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::MushroomGenerator::
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
    Mobs::MonsterProperties properties(speed);

    //algorithms
    std::pair<float, float> collisionParams = std::make_pair<float, float>(std::stof(data.at("COLLISION_ANALYSIS_STEP")),
                                                                           std::stof(data.at("COLLISION_ANALYSIS_STEP")));

    std::shared_ptr<Material::Algorithms> algorithms(
            new Material::Algorithms(m_source.getAlgpool()->loadCollision(collisionParams)));

    unifier.addMonster(new Mobs::Mushroom(
            properties, area,
            std::shared_ptr<Components::ISpriteBox>(
                    new Components::SpriteBox(spriteArea, m_source.getTexture(data.at("TEXTURE")))), algorithms));
}
