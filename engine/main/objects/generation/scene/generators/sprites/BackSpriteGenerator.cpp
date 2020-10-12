//
// Created by roman on 04.10.2020.
//

#include "BackSpriteGenerator.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reducing/area.h"

Generate::BackSpriteGenerator::BackSpriteGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::BackSpriteGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addBackSprite(new Components::SpriteBox(physicalArea(data), m_source.getTexture(data.at("TEXTURE"))));
}
