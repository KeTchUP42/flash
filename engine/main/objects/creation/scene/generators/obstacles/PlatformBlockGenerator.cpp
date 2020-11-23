//
// Created by roman on 06.10.2020.
//

#include "PlatformBlockGenerator.h"
#include "../../../../material/common/algorithms/Algorithms.h"
#include "../../../../material/obstacles/blocks/sprite-visible/single/PlatformBlock.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/PropertiesReduction.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Creation::PlatformBlockGenerator::PlatformBlockGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::PlatformBlockGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addBlock(new Obstacles::PlatformBlock(
            RD::loadObstacleProperties(data),
            std::make_shared<Components::SpriteBox>(
                    RD::commonArea(data), m_source.getTexture(data.at("TEXTURE"))),
            RD::loadAlgorithms(data, m_source)));
}
