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

    //speed
    Components::Speed speed(std::stof(data.at("X_SPEED")), std::stof(data.at("Y_SPEED")));

    //properties
    Mobs::MonsterProperties properties(speed);

    //texture
    auto texture = m_source.getTexture(data.at("TEXTURE"));

    //algorithms
    std::pair<float, float> collisionParams = std::make_pair<float, float>(std::stof(data.at("COLLISION_ANALYSIS_STEP")),
                                                                           std::stof(data.at("COLLISION_ANALYSIS_STEP")));

    std::shared_ptr<Material::Algorithms> algorithms(
            new Material::Algorithms(m_source.getAlgpool()->loadCollision(collisionParams)));

    unifier.addMonster(new Mobs::Mushroom(
            properties,
            std::shared_ptr<Components::ISpriteBox>(
                    new Components::SpriteBox(
                            point,
                            size,
                            texture)), algorithms));
}
