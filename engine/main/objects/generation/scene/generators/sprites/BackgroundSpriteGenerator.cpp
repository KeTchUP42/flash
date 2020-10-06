//
// Created by roman on 30.09.2020.
//

#include "BackgroundSpriteGenerator.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"

Generate::BackgroundSpriteGenerator::BackgroundSpriteGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::BackgroundSpriteGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addBackSprite(new Components::SpriteBox(
            Components::Area(Components::Point(0, 0), Components::Size(target.getSize().x, target.getSize().y), 0),
            m_source.getTexture(data.at("TEXTURE"))));
}
