//
// Created by roman on 01.10.2020.
//

#include "MushroomGenerator.h"
#include "../../../../material/mobs/custom/mushroom/Mushroom.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/PropertiesReduction.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Creation::MushroomGenerator::MushroomGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::MushroomGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    //mushroom properties
    Mobs::MushroomProperties mushroomProperties(
            std::stof(data.at("PUNCH_POWER")),
            std::stof(data.at("ELASTICITY_LEVEL")));

    unifier.addMob(new Mobs::Mushroom(
            loadMobProperties(data), commonArea(data),
            std::shared_ptr<Components::ISpriteBox>(
                    new Components::SpriteBox(spriteArea(data), m_source.getTexture(data.at("TEXTURE")))),
            loadAlgorithms(data, m_source), mushroomProperties));
}
