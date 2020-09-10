//
// Created by roman on 09.09.2020.
//

#include "Unifier.h"

Unite::Unifier::Unifier(Screen::StateChangeable *context) {}

void Unite::Unifier::addPlayer(Mobs::Player *player) noexcept {
    _players.push_back(std::shared_ptr<Mobs::Player>(player));
}

void Unite::Unifier::addPlayer(const std::shared_ptr<Mobs::Player> &player) noexcept {
    _players.push_back(player);
}

void Unite::Unifier::removePlayer(const std::shared_ptr<Mobs::Player> &player) noexcept {
    _players.remove(player);
}

const std::list<std::shared_ptr<Mobs::Player>> &Unite::Unifier::getPlayers() const noexcept {
    return _players;
}
