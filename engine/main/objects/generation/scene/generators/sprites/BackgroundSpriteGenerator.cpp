//
// Created by roman on 30.09.2020.
//

#include "BackgroundSpriteGenerator.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"

Generating::BackgroundSpriteGenerator::BackgroundSpriteGenerator(Generating::Pools::SourcePool &pool) : Generator(pool) {}

void Generating::BackgroundSpriteGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addBackSprite(
            new Components::SpriteBox(Components::Point(0, 0),
                                      Components::Size(target.getSize().x, target.getSize().y),
                                      m_sourcePool.getTexture(data.at("TEXTURE"))));
}
