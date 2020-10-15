//
// Created by roman on 01.10.2020.
//

#include "BasicPlayerGenerator.h"
#include "../../../../material/common/algorithms/Algorithms.h"
#include "../../../../material/mobs/player/custom/basic/BasicPlayer.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/PropertiesReduction.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"

Generate::BasicPlayerGenerator::BasicPlayerGenerator(Generate::Pools::SourcePool &pool) : Generator(pool) {}

void Generate::BasicPlayerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, sf::RenderWindow &target) {
    //player properties
    Mobs::BasicPlayerProperties playerProperties(
            std::stof(data.at("MOVE_SPEED")),
            std::stof(data.at("MAX_MOVE_SPEED")),
            std::stof(data.at("JUMP_SPEED")));

    Mobs::Player *player = new Mobs::BasicPlayer(
            loadPlayerProperties(data), commonArea(data),
            std::make_shared<Components::SpriteBox>(
                    spriteArea(data), m_source.getTexture(data.at("TEXTURE"))),
            loadAlgorithms(data, m_source), playerProperties);

    player->loadKeyMap(data.at("KEYMAP"), m_source.getManager());
    unifier.addPlayer(player);
}
