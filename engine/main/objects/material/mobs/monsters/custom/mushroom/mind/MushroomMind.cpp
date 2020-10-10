//
// Created by roman on 07.10.2020.
//

#include "MushroomMind.h"

Mobs::MushroomMind::MushroomMind(Mobs::Mushroom *holder) : Mind(holder) {}

void Mobs::MushroomMind::analyze(Unite::Unifier *unifier) noexcept {

    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {
        if (m_holder->m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(player.get(), m_holder)) {
            if (player->getPosition().y < m_holder->getPosition().y) {
                player->setSpeed(Components::Speed(
                        player->getSpeed().xSpeed,
                        static_cast<int>(-1 * (player->getSpeed().ySpeed + player->getSpeed().ySpeed * m_holder->m_mushroom.elasticityLevel))
                ));
            }
        }
    }

    Mobs::Monster *monster;
    if ((monster = m_holder->m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(m_holder, unifier->getMonsters())) != nullptr) {
        if (m_holder->getSpeed().xSpeed * monster->getSpeed().xSpeed <= 0) {
            monster->setSpeed(Components::Speed((m_holder->getSpeed().xSpeed > 0 ? 1 : -1) * m_holder->m_mushroom.punchPower,
                                                monster->getSpeed().ySpeed - m_holder->m_mushroom.punchPower * 2));

            if (std::abs(m_holder->m_mushroom.punchPower) > std::abs(m_holder->getSpeed().xSpeed)) {
                m_holder->m_properties.speed.xSpeed = 0;
            } else {
                m_holder->m_properties.speed.xSpeed = -m_holder->getSpeed().xSpeed + m_holder->m_mushroom.punchPower *
                                                      ((m_holder->getSpeed().xSpeed > 0 ? -1 : 1) * (m_holder->m_mushroom.punchPower > 0 ? -1 : 1));
            }
        }
    }

    m_holder->selfMove(unifier);
}
