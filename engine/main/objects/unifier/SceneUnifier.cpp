//
// Created by roman on 09.09.2020.
//

#include "SceneUnifier.h"

void Unite::SceneUnifier::draw(sf::RenderWindow &target) const noexcept {

    for (const std::shared_ptr<Components::ISprite> &sprite: m_back) {
        sprite->draw(target);
    }

    for (const std::shared_ptr<Components::Text> &text: m_texts) {
        text->draw(target);
    }

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: m_obstacles) {
        obstacle->draw(target);
    }

    for (const std::shared_ptr<Mobs::Mob> &mob: m_mobs) {
        mob->draw(target);
    }

    for (const std::shared_ptr<Mobs::Player> &player: m_players) {
        player->draw(target);
    }

    for (const std::shared_ptr<Components::ISprite> &sprite: m_front) {
        sprite->draw(target);
    }
}

void Unite::SceneUnifier::refresh() {

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: m_obstacles) {
        obstacle->updateCoordinates();
    }

    for (const std::shared_ptr<Mobs::Player> &player: m_players) {
        player->updateCoordinates();
    }

    for (const std::shared_ptr<Mobs::Mob> &mob: m_mobs) {
        mob->updateCoordinates();
    }

    for (const std::shared_ptr<Triggers::Trigger> &trigger: m_triggers) {
        if (trigger->verifyTrigger(this) == Triggers::ResultCodes::STOP) return;
    }

    for (const std::shared_ptr<Effects::Effect> &effect: m_effects) {
        effect->applyEffect(this);
    }

    for (const std::shared_ptr<Mobs::Mob> &mob: m_mobs) {
        mob->selfAction(this);
    }

    for (const std::shared_ptr<Mobs::Player> &player: m_players) {
        player->selfAction(this);
    }

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: m_obstacles) {
        obstacle->selfAction(this);
    }

    m_mobs.remove_if([](const std::shared_ptr<Mobs::Mob> &mob) -> bool {
        return mob->getProperties().isRemovable;
    });

    m_players.remove_if([](const std::shared_ptr<Mobs::Player> &player) -> bool {
        return player->getProperties().isRemovable;
    });

    for (const std::shared_ptr<Obstacles::Obstacle> &obstacle: m_obstacles) {
        obstacle->updateLocation();
    }

    for (const std::shared_ptr<Mobs::Player> &player: m_players) {
        player->updateLocation();
    }

    for (const std::shared_ptr<Mobs::Mob> &mob: m_mobs) {
        mob->updateLocation();
    }
}

void Unite::SceneUnifier::update(const sf::Event &event, View::Window &sender) {

    for (const std::shared_ptr<Triggers::Trigger> &trigger: m_triggers) {
        trigger->update(event, sender);
    }

    for (const std::shared_ptr<Mobs::Player> &player: m_players) {
        player->update(event, sender);
    }
}
