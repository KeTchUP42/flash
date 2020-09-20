//
// Created by roman on 09.09.2020.
//

#include "GeneralUnifier.h"

void Unite::GeneralUnifier::draw(sf::RenderWindow &target) const noexcept {

    for (const std::shared_ptr<Components::ISprite> &sprite: _back) {
        sprite->draw(target);
    }

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: _obstacles) {
        obstacle->draw(target);
    }

    for (const std::shared_ptr<Mobs::Monster> &monster: _monsters) {
        monster->draw(target);
    }

    for (const std::shared_ptr<Mobs::Player> &player: _players) {
        player->draw(target);
    }

    for (const std::shared_ptr<Components::ISprite> &sprite: _front) {
        sprite->draw(target);
    }
}

void Unite::GeneralUnifier::refresh() {

    for (const std::shared_ptr<Triggers::Trigger> &trigger: _triggers) {
        trigger->verifyTrigger(this);
    }

    for (const std::shared_ptr<Effects::Effect> &effect: _effects) {
        effect->applyEffect(this);
    }

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: _obstacles) {
        obstacle->selfAction(this);
    }

    for (const std::shared_ptr<Mobs::Player> &player: _players) {
        player->selfAction(this);
    }

    for (const std::shared_ptr<Mobs::Monster> &monster: _monsters) {
        monster->selfAction(this);
    }
}

void Unite::GeneralUnifier::update(const sf::Event &event, sf::RenderWindow &sender) {

    for (const std::shared_ptr<Triggers::Trigger> &trigger: _triggers) {
        trigger->update(event, sender);
    }

    for (const std::shared_ptr<Components::ISprite> &sprite: _back) {
        sprite->update(event, sender);
    }

    for (const std::shared_ptr<Mobs::Player> &player: _players) {
        player->update(event, sender);
    }

    for (const std::shared_ptr<Mobs::Monster> &monster: _monsters) {
        monster->update(event, sender);
    }

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: _obstacles) {
        obstacle->update(event, sender);
    }

    for (const std::shared_ptr<Components::ISprite> &sprite: _front) {
        sprite->update(event, sender);
    }
}
