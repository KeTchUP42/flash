//
// Created by roman on 22.11.2020.
//

#include "SlimeGenerator.h"
#include "../../../../material/mobs/custom/slime/Slime.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/PropertiesReduction.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Creation::SlimeGenerator::SlimeGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::SlimeGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    //Slime properties.
    Mobs::SlimeProperties slimeProperties(
            std::stof(data.at("MOVE_SPEED")),
            std::stof(data.at("JUMP_SPEED")),
            std::stoi(data.at("JUMP_RATE_COEFFICIENT")),
            std::stof(data.at("PUNCH_POWER")),
            std::stof(data.at("PUNCH_DAMAGE")),
            std::stof(data.at("ELASTIC_COEFFICIENT")),
            std::stof(data.at("FRICTION_COEFFICIENT")),
            std::stoi(data.at("MIN_SPLIT_SIZE")),
            std::stof(data.at("SPLITTING_COEFFICIENT")),
            std::stoi(data.at("SPLIT_SLIMES_NUMBER")));

    unifier.addStandAloneMob(new Mobs::Slime(
            RD::loadMobProperties(data), RD::commonArea(data),
            std::shared_ptr<Components::ISpriteBox>(
                    new Components::SpriteBox(RD::spriteArea(data), m_source.getTexture(data.at("TEXTURE")))),
            RD::loadAlgorithms(data, m_source), slimeProperties));
}
