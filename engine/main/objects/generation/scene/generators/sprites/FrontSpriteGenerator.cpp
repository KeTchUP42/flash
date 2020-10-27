//
// Created by roman on 04.10.2020.
//

#include "FrontSpriteGenerator.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/AreaReduction.h"

Generate::FrontSpriteGenerator::FrontSpriteGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::FrontSpriteGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addFrontSprite(new Components::SpriteBox(commonArea(data), m_source.getTexture(data.at("TEXTURE"))));
}
