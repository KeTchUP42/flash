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

Generate::PlatformBlockGenerator::PlatformBlockGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::PlatformBlockGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addObstacle(new Obstacles::PlatformBlock(
            loadObstacleProperties(data),
            std::make_shared<Components::SpriteBox>(
                    commonArea(data), m_source.getTexture(data.at("TEXTURE"))),
            loadAlgorithms(data, m_source)));
}
