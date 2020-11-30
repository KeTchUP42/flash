//
// Created by roman on 29.11.2020.
//

#include "ShootingPlayerGenerator.h"
#include "../../../../material/mobs/players/custom/jumping/properties/JumpingPlayerProperties.h"
#include "../../../../material/particles/optimizer/bullets/BulletsOptimizer.h"
#include "../../../../material/mobs/players/custom/shooting/ShootingPlayer.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../reduction/PropertiesReduction.h"
#include "../reduction/ElementaryReduction.h"
#include "../reduction/CustomReduction.h"
#include "../reduction/AreaReduction.h"
#include "../reduction/KeyMapBuilder.h"

Creation::ShootingPlayerGenerator::ShootingPlayerGenerator(Creation::Pools::SourcePool &pool) : Generator(pool) {}

void Creation::ShootingPlayerGenerator::
load(const IniUtil::Analyzer::IniBlock &data, Unite::Unifier &unifier, View::Window &window) {
    //Player properties.
    Mobs::JumpingPlayerProperties jmpPlayerProperties(
            std::stof(data.at("MOVE_SPEED")),
            std::stof(data.at("MAX_MOVE_SPEED")),
            std::stof(data.at("JUMP_DASH_SPEED")));

    Mobs::ShootingPlayerProperties shtPlayerProperties(
            std::stof(data.at("BULLETS_FLIGHT_SPEED")),
            std::stof(data.at("BULLETS_DAMAGE")),
            std::atoi(data.at("BULLETS_UNDER_EFFECTS").c_str()),
            {RD::size(data, "BULLETS_SIZE"),
             std::stof(data.at("BULLETS_ANGLE"))},
            {RD::size(data, "BULLETS_SPRITE_SIZE"),
             std::stof(data.at("BULLETS_SPRITE_ANGLE"))},
            m_source.getTexture(data.at("BULLETS_RIGHT_TEXTURE")),
            m_source.getTexture(data.at("BULLETS_LEFT_TEXTURE")));

    Mobs::Player *player = new Mobs::ShootingPlayer(
            RD::loadMobProperties(data), RD::commonArea(data),
            std::make_shared<Components::SpriteBox>(
                    RD::spriteArea(data), m_source.getTexture(data.at("TEXTURE"))),
            RD::loadAlgorithms(data, m_source), jmpPlayerProperties, shtPlayerProperties,
            new Particles::BulletsOptimizer(window.getWindow().getSize()));

    RD::KeyMapBuilder builder(data.at("KEYMAP"), m_source);
    builder.setKey(Mobs::KeyAlias::Right, "MAP", "Right")
            .setKey(Mobs::KeyAlias::Left, "MAP", "Left")
            .setKey(Mobs::KeyAlias::Jump, "MAP", "Jump")
            .setKey(Mobs::KeyAlias::ShootRight, "MAP", "ShootRight")
            .setKey(Mobs::KeyAlias::ShootLeft, "MAP", "ShootLeft");

    player->loadKeyMap(builder.getKeyMap());
    unifier.addPlayer(player);
}
