//
// Created by roman on 07.10.2020.
//

#include "MushroomMind.h"

Mobs::MushroomMind::MushroomMind(Mobs::Mushroom *holder) : Mind(holder) {}

void Mobs::MushroomMind::analyze(Unite::Unifier *unifier) noexcept {

    for (const std::shared_ptr<Mobs::Player> &player : unifier->getPlayers()) {
        if (m_holder->m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(player.get(), m_holder)) {
            player->setSpeed(Components::Speed(
                    player->getSpeed().xSpeed,
                    static_cast<int>(-1 * (player->getSpeed().ySpeed + player->getSpeed().ySpeed * 0.25))
            ));
        }
    }

    Mobs::Monster *monster;
    if ((monster = m_holder->m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(m_holder, unifier->getMonsters())) != nullptr) {
        if (((m_holder->getSpeed().xSpeed < 0) && (monster->getSpeed().xSpeed >= 0)) ||
            ((m_holder->getSpeed().xSpeed > 0) && (monster->getSpeed().xSpeed <= 0))) {
            monster->setSpeed(Components::Speed(m_holder->getSpeed().xSpeed > 0 ? 5 : -5, monster->getSpeed().ySpeed - 10));
            m_holder->m_properties.speed.xSpeed += m_holder->getSpeed().xSpeed > 0 ? -1 : 1;
        }
    }

    m_holder->selfMove(unifier);
}
