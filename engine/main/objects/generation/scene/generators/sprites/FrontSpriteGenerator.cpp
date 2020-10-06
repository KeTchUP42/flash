//
// Created by roman on 04.10.2020.
//

#include "FrontSpriteGenerator.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"

Generate::FrontSpriteGenerator::FrontSpriteGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::FrontSpriteGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //point
    Components::Point point(std::stof(data.at("X")), std::stof(data.at("Y")));

    //size
    Components::Size size(std::atoi(data.at("WIDTH").c_str()), std::atoi(data.at("HEIGHT").c_str()));

    //angle
    float angle = std::stof(data.at("ANGLE"));

    unifier.addFrontSprite(new Components::SpriteBox(Components::Area(point, size, angle),
                                                     m_source.getTexture(data.at("TEXTURE"))));
}
