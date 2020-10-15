//
// Created by roman on 06.10.2020.
//

#include "DullInvisibleBlockGenarator.h"
#include "../../../../material/common/algorithms/Algorithms.h"
#include "../../../../material/obstacles/blocks/invisible/DullInvisibleBlock.h"
#include "../reduction/AlgorithmsReduction.h"
#include "../reduction/PropertiesReduction.h"
#include "../reduction/AreaReduction.h"

Generate::DullInvisibleBlockGenarator::DullInvisibleBlockGenarator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::DullInvisibleBlockGenarator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    unifier.addObstacle(new Obstacles::DullInvisibleBlock(
            loadObstacleProperties(data), physicalArea(data), loadAlgorithms(data, m_source)));
}
