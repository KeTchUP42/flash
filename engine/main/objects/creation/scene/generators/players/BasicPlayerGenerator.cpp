//
// Created by roman on 01.10.2020.
//

#include "BasicPlayerGenerator.h"
#include "../../../../material/mobs/players/custom/basic/BasicPlayer.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/PropertiesReduction.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"
#include "../reduction/KeyMapBuilder.h"

Creation::BasicPlayerGenerator::BasicPlayerGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::BasicPlayerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    //player properties
    Mobs::BasicPlayerProperties playerProperties(
            std::stof(data.at("MOVE_SPEED")),
            std::stof(data.at("MAX_MOVE_SPEED")),
            std::stof(data.at("JUMP_SPEED")));

    Mobs::Player *player = new Mobs::BasicPlayer(
            loadMobProperties(data), commonArea(data),
            std::make_shared<Components::SpriteBox>(
                    spriteArea(data), m_source.getTexture(data.at("TEXTURE"))),
            loadAlgorithms(data, m_source), playerProperties);

    KeyMapBuilder builder(data.at("KEYMAP"), m_source);
    builder.setKey(Mobs::KeyAlias::Right, "MAP", "Right")
            .setKey(Mobs::KeyAlias::Left, "MAP", "Left")
            .setKey(Mobs::KeyAlias::Jump, "MAP", "Jump")
            .setKey(Mobs::KeyAlias::Use, "MAP", "Use");

    player->loadKeyMap(builder.getKeyMap());
    unifier.addPlayer(player);
}
