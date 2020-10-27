//
// Created by roman on 04.10.2020.
//

#include "BackSpriteGenerator.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/AreaReduction.h"

Generate::BackSpriteGenerator::BackSpriteGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::BackSpriteGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addBackSprite(new Components::SpriteBox(commonArea(data), m_source.getTexture(data.at("TEXTURE"))));
}
