//
// Created by roman on 09.09.2020.
//

#include "GeneralUnifier.h"

Unite::GeneralUnifier::GeneralUnifier(Screen::StateChangeable *context) : Unifier(context) {}

void Unite::GeneralUnifier::draw(sf::RenderWindow &target) const noexcept {
    //Back sprites

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: _obstacles) {
        obstacle->draw(target);
    }

    // Mobs

    for (const std::shared_ptr<Mobs::Player> &player: _players) {
        player->draw(target);
    }

    // front sprites.
}

void Unite::GeneralUnifier::refresh() {

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: _obstacles) {
        obstacle->selfAction(this);
    }

    for (const std::shared_ptr<Effects::Effect> &effect: _effects) {
        effect->applyEffect(this);
    }

    for (const std::shared_ptr<Mobs::Player> &player: _players) {
        player->selfAction(this);
    }

    //mobs

    //..

    //trigers

}

void Unite::GeneralUnifier::update(const sf::Event &event, sf::RenderWindow &sender) {
    for (const std::shared_ptr<Mobs::Player> &player: _players) {
        player->update(event, sender);
    }
    //mobs

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: _obstacles) {
        obstacle->update(event, sender);
    }

    //all observers
}
