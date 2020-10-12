//
// Created by roman on 01.10.2020.
//

#include "MushroomGenerator.h"
#include "../../../../material/mobs/monsters/custom/mushroom/Mushroom.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reducing/area.h"

Generate::MushroomGenerator::MushroomGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::MushroomGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //properties
    Components::Speed speed(std::stof(data.at("X_SPEED")), std::stof(data.at("Y_SPEED")));
    Mobs::MonsterProperties properties(speed);

    //mushroom properties
    Mobs::MushroomProperties mushroomProperties(std::stof(data.at("PUNCH_POWER")), std::stof(data.at("ELASTICITY_LEVEL")));

    //algorithms
    std::pair<float, float> collisionParams = std::make_pair<float, float>(std::stof(data.at("COLLISION_ANALYSIS_STEP")),
                                                                           std::stof(data.at("COLLISION_ANALYSIS_STEP")));

    std::shared_ptr<Material::Algorithms> algorithms(
            new Material::Algorithms(m_source.getAlgpool()->loadCollision(collisionParams)));

    unifier.addMonster(new Mobs::Mushroom(
            properties, physicalArea(data),
            std::shared_ptr<Components::ISpriteBox>(
                    new Components::SpriteBox(spriteArea(data), m_source.getTexture(data.at("TEXTURE")))), algorithms, mushroomProperties));
}
