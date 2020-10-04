//
// Created by roman on 04.10.2020.
//

#include "BackSpriteGenerator.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"

Generate::BackSpriteGenerator::BackSpriteGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::BackSpriteGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //point
    Components::Point point(std::stof(data.at("X")), std::stof(data.at("Y")));

    //size
    Components::Size size(std::atoi(data.at("WIDTH").c_str()), std::atoi(data.at("HEIGHT").c_str()));

    unifier.addBackSprite(new Components::SpriteBox(point, size, m_source.getTexture(data.at("TEXTURE"))));
}
