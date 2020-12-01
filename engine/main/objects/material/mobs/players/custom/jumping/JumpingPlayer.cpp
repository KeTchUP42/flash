//
// Created by roman on 09.09.2020.
//

#include "JumpingPlayer.h"
#include "../../../../reduction/mobs/MobsAnalysisReduction.h"
#include "../../../../reduction/collision/CollisionReduction.h"

Mobs::JumpingPlayer::JumpingPlayer(
        const Material::MaterialProperties &material_properties,
        const Mobs::MobProperties &properties,
        const Components::Area &area,
        const std::shared_ptr<Components::ISpriteBox> &sprite,
        const std::shared_ptr<Material::Algorithms> &algorithms,
        const Mobs::JumpingPlayerProperties &jumping
) : AnalyzingPlayer(material_properties, properties, area, sprite, algorithms), m_jumping(jumping) {}

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
            if ((std::abs(m_material_properties.speed.xSpeed) < m_jumping.maxMoveSpeed) &&
                (m_material_properties.speed.xSpeed + m_jumping.moveSpeed <= m_jumping.maxMoveSpeed)) {
                this->addSpeed(m_jumping.moveSpeed, 0);
            }
        }
        if (event.key.code == m_keyMap[KeyAlias::Left]) {
            if ((std::abs(m_material_properties.speed.xSpeed) < m_jumping.maxMoveSpeed) &&
                (m_material_properties.speed.xSpeed - m_jumping.moveSpeed >= -m_jumping.maxMoveSpeed)) {
                this->addSpeed(-m_jumping.moveSpeed, 0);
            }
        }
        if (event.key.code == m_keyMap[KeyAlias::Jump]) {
            if (m_material_properties.speed.ySpeed == 0) { this->addSpeed(0, -m_jumping.jumpSpeed); }
        }
    }
}