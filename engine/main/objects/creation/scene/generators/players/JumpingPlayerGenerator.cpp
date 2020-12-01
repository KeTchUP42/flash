//
// Created by roman on 01.10.2020.
//

#include "JumpingPlayerGenerator.h"
#include "../../../../material/mobs/players/custom/jumping/JumpingPlayer.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/PropertiesReduction.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"
#include "../reduction/KeyMapBuilder.h"

Creation::JumpingPlayerGenerator::JumpingPlayerGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::JumpingPlayerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    //Player properties.
    Mobs::JumpingPlayerProperties playerProperties(
            std::stof(data.at("MOVE_SPEED")),
            std::stof(data.at("MAX_MOVE_SPEED")),
            std::stof(data.at("JUMP_DASH_SPEED")));

    Mobs::Player *player = new Mobs::JumpingPlayer(
            RD::loadMaterialProperties(data),
            RD::loadMobProperties(data), RD::commonArea(data),
            std::make_shared<Components::SpriteBox>(
                    RD::spriteArea(data), m_source.getTexture(data.at("TEXTURE"))),
            RD::loadAlgorithms(data, m_source), playerProperties);

    RD::KeyMapBuilder builder(data.at("KEYMAP"), m_source);
    builder.setKey(Mobs::KeyAlias::Right, "MAP", "Right")
            .setKey(Mobs::KeyAlias::Left, "MAP", "Left")
            .setKey(Mobs::KeyAlias::Jump, "MAP", "Jump");

    player->loadKeyMap(builder.getKeyMap());
    unifier.addPlayer(player);
}
