//
// Created by roman on 29.09.2020.
//

#include "DullBlockGenerator.h"
#include "../../../../material/obstacles/blocks/sprite-visible/single/DullBlock.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/PropertiesReduction.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Creation::DullBlockGenerator::DullBlockGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::DullBlockGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addBlock(new Obstacles::DullBlock(
            loadObstacleProperties(data),
            std::make_shared<Components::SpriteBox>(
                    commonArea(data), m_source.getTexture(data.at("TEXTURE"))),
            loadAlgorithms(data, m_source)));
}
