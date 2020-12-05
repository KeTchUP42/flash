//
// Created by roman on 29.09.2020.
//

#include "DullBlockGenerator.h"
#include "../../../../material/obstacles/blocks/custom/sprite-visible/single/dull-block/DullBlock.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/PropertiesReduction.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Creation::DullBlockGenerator::DullBlockGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::DullBlockGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addBlock(new Obstacles::DullBlock(
            RD::loadMaterialProperties(data),
            RD::loadObstacleProperties(data),
            std::make_shared<Components::SpriteBox>(
                    RD::commonArea(data), m_source.getTexture(data.at("TEXTURE"))),
            RD::loadAlgorithms(data, m_source)));
}
