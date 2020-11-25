//
// Created by roman on 09.09.2020.
//

#include "BasicPlayer.h"
#include "../../../common/reduction/MobsAnalysisReduction.h"
#include "../../../common/reduction/MobsCollisionReduction.h"

Mobs::BasicPlayer::BasicPlayer(
        const Mobs::MobProperties &properties,
        const Components::Area &area,
        const std::shared_ptr<Components::ISpriteBox> &sprite,
        const std::shared_ptr<Material::Algorithms> &algorithms,
        const Mobs::BasicPlayerProperties &params
) : BasePlayer(properties, area, sprite, algorithms), m_basic(params) {}

void Mobs::BasicPlayer::selfAction(Unite::Unifier *unifier) {
    RD::healthAnalysis(*this);
    if (this->isDead()) {
        unifier->addFrameAction([this](Unite::Unifier *unifier1) -> void {
            unifier1->removePlayer(this);
        });
    } else {
        RD::abscissaBlocksNaturalCollision(this, *m_algorithms.get(), unifier);
        RD::ordinateBlocksNaturalCollision(this, *m_algorithms.get(), unifier);
    }
}

void Mobs::BasicPlayer::update(const sf::Event &event, View::Window &sender) {
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == m_keyMap[KeyAlias::Right])) {
        if ((std::abs(m_properties.speed.xSpeed) < m_basic.maxMoveSpeed) && (m_properties.speed.xSpeed + m_basic.moveSpeed <= m_basic.maxMoveSpeed)) {
            this->addSpeed(m_basic.moveSpeed, 0);
        }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == m_keyMap[KeyAlias::Left])) {
        if ((std::abs(m_properties.speed.xSpeed) < m_basic.maxMoveSpeed) && (m_properties.speed.xSpeed - m_basic.moveSpeed >= -m_basic.maxMoveSpeed)) {
            this->addSpeed(-m_basic.moveSpeed, 0);
        }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == m_keyMap[KeyAlias::Jump])) {
        if (m_properties.speed.ySpeed == 0) { this->addSpeed(0, -m_basic.jumpSpeed); }
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == m_keyMap[KeyAlias::Use])) {
        //..
    }
}