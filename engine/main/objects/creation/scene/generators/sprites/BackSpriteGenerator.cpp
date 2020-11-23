//
// Created by roman on 04.10.2020.
//

#include "BackSpriteGenerator.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/AreaReduction.h"

Creation::BackSpriteGenerator::BackSpriteGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::BackSpriteGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addBackSprite(new Components::SpriteBox(RD::commonArea(data), m_source.getTexture(data.at("TEXTURE"))));
}
