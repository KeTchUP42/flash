//
// Created by roman on 09.09.2020.
//

#include "JumpingPlayer.h"
#include "../../../common/reduction/MobsAnalysisReduction.h"
#include "../../../common/reduction/MobsCollisionReduction.h"

Mobs::JumpingPlayer::JumpingPlayer(
        const Mobs::MobProperties &properties,
        const Components::Area &area,
        const std::shared_ptr<Components::ISpriteBox> &sprite,
        const std::shared_ptr<Material::Algorithms> &algorithms,
        const Mobs::JumpingPlayerProperties &params
) : AnalyzingPlayer(properties, area, sprite, algorithms), m_player(params) {}

void Mobs::JumpingPlayer::selfAction(Unite::Unifier *unifier) {
    RD::healthAnalysis(*this);
    if (this->isDead()) {
        unifier->addFrameAction([this](Unite::Unifier *unifier1) -> void {
            unifier1->removePlayer(this);
        });
    } else {
        RD::abscissaBlocksNaturalCollision(this, *m_algorithms.get(), unifier);
        RD::ordinateBlocksNaturalCollision(this, *m_algorithms.get(), unifier);

        this->handleEventsList(unifier);
    }
}

void Mobs::JumpingPlayer::handleEvent(const sf::Event &event, Unite::Unifier *unifier) noexcept {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == m_keyMap[KeyAlias::Right]) {
            if ((std::abs(m_properties.speed.xSpeed) < m_player.maxMoveSpeed) && (m_properties.speed.xSpeed + m_player.moveSpeed <= m_player.maxMoveSpeed)) {
                this->addSpeed(m_player.moveSpeed, 0);
            }
        }
        if (event.key.code == m_keyMap[KeyAlias::Left]) {
            if ((std::abs(m_properties.speed.xSpeed) < m_player.maxMoveSpeed) && (m_properties.speed.xSpeed - m_player.moveSpeed >= -m_player.maxMoveSpeed)) {
                this->addSpeed(-m_player.moveSpeed, 0);
            }
        }
        if (event.key.code == m_keyMap[KeyAlias::Jump]) {
            if (m_properties.speed.ySpeed == 0) { this->addSpeed(0, -m_player.jumpSpeed); }
        }
    }
}