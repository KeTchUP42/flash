//
// Created by roman on 09.09.2020.
//

#include "CommonUnifier.h"

Unite::CommonUnifier::CommonUnifier(Screen::StateChangeable *context) : Unifier(context) {}

void Unite::CommonUnifier::draw(sf::RenderWindow &target) const noexcept {
    //..

    for (const std::shared_ptr<Mobs::Player> &player: _players) {
        player->draw(target);
    }
}

void Unite::CommonUnifier::refresh() {
    for (const std::shared_ptr<Effects::Effect> &effect: _effects) {
        effect->applyEffect(this);
    }

    for (const std::shared_ptr<Mobs::Player> &player: _players) {
        player->selfAction(this);
    }
    //..
}

void Unite::CommonUnifier::update(const sf::Event &event, sf::RenderWindow &sender) {
    for (const std::shared_ptr<Mobs::Player> &player: _players) {
        player->update(event, sender);
    }
    //..
}
