//
// Created by roman on 01.10.2020.
//

#include "MushroomGenerator.h"
#include "../../../../material/mobs/monsters/custom/mushroom/Mushroom.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/PropertiesReduction.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Generate::MushroomGenerator::MushroomGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::MushroomGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //mushroom properties
    Mobs::MushroomProperties mushroomProperties(std::stof(data.at("PUNCH_POWER")), std::stof(data.at("ELASTICITY_LEVEL")));

    unifier.addMonster(new Mobs::Mushroom(
            loadMonsterProperties(data), commonArea(data),
            std::shared_ptr<Components::ISpriteBox>(
                    new Components::SpriteBox(spriteArea(data), m_source.getTexture(data.at("TEXTURE")))),
            loadAlgorithms(data, m_source), mushroomProperties));
}
