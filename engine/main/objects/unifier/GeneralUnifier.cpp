//
// Created by roman on 09.09.2020.
//

#include "GeneralUnifier.h"

void Unite::GeneralUnifier::draw(sf::RenderWindow &target) const noexcept {

    for (const std::shared_ptr<Components::ISprite> &sprite: _backSprites) {
        sprite->draw(target);
    }

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: _obstacles) {
        obstacle->draw(target);
    }

    // Monsters

    for (const std::shared_ptr<Mobs::Player> &player: _players) {
        player->draw(target);
    }

    for (const std::shared_ptr<Components::ISprite> &sprite: _frontSprites) {
        sprite->draw(target);
    }
}

void Unite::GeneralUnifier::refresh() {

    for (const std::shared_ptr<Effects::Effect> &effect: _effects) {
        effect->applyEffect(this);
    }

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: _obstacles) {
        obstacle->selfAction(this);
    }

    for (const std::shared_ptr<Mobs::Player> &player: _players) {
        player->selfAction(this);
    }

    //mobs

    //..

    //trigers
}

void Unite::GeneralUnifier::update(const sf::Event &event, sf::RenderWindow &sender) {

    for (const std::shared_ptr<Components::ISprite> &sprite: _backSprites) {
        sprite->update(event, sender);
    }

    for (const std::shared_ptr<Mobs::Player> &player: _players) {
        player->update(event, sender);
    }

    //You can add monsters to update circle.

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: _obstacles) {
        obstacle->update(event, sender);
    }

    for (const std::shared_ptr<Components::ISprite> &sprite: _frontSprites) {
        sprite->update(event, sender);
    }
}
