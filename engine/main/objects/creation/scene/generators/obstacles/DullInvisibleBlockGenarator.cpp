//
// Created by roman on 06.10.2020.
//

#include "DullInvisibleBlockGenarator.h"
#include "../../../../material/common/algorithms/Algorithms.h"
#include "../../../../material/obstacles/blocks/invisible/DullInvisibleBlock.h"
#include "../reduction/PropertiesReduction.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Creation::DullInvisibleBlockGenarator::DullInvisibleBlockGenarator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::DullInvisibleBlockGenarator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    unifier.addBlock(new Obstacles::DullInvisibleBlock(
            loadObstacleProperties(data), commonArea(data), loadAlgorithms(data, m_source)));
}
