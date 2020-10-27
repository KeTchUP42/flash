//
// Created by roman on 30.09.2020.
//

#include "BackgroundSpriteGenerator.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"

Generate::BackgroundSpriteGenerator::BackgroundSpriteGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::BackgroundSpriteGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addBackSprite(new Components::SpriteBox(
            Components::Area(Components::Point(0, 0), Components::Size(window.getWindow().getSize().x, window.getWindow().getSize().y), 0),
            m_source.getTexture(data.at("TEXTURE"))));
}
