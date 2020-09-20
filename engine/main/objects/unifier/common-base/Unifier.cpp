//
// Created by roman on 09.09.2020.
//

#include "Unifier.h"

void Unite::Unifier::addBackSprite(Components::ISprite *sprite) noexcept {
    _back.push_back(std::shared_ptr<Components::ISprite>(sprite));
}

void Unite::Unifier::addBackSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    _back.push_back(sprite);
}

void Unite::Unifier::removeBackSprite(Components::ISprite *sprite) noexcept {
    _back.remove_if([sprite](const std::shared_ptr<Components::ISprite> &sprt) -> bool {
        return sprt.get() == sprite;
    });
}

void Unite::Unifier::removeBackSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    _back.remove(sprite);
}

const std::list<std::shared_ptr<Components::ISprite>> &Unite::Unifier::getBackSprites() const noexcept {
    return _back;
}

void Unite::Unifier::addFrontSprite(Components::ISprite *sprite) noexcept {
    _front.push_back(std::shared_ptr<Components::ISprite>(sprite));
}

void Unite::Unifier::addFrontSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    _front.push_back(sprite);
}

void Unite::Unifier::removeFrontSprite(Components::ISprite *sprite) noexcept {
    _front.remove_if([sprite](const std::shared_ptr<Components::ISprite> &sprt) -> bool {
        return sprt.get() == sprite;
    });
}

void Unite::Unifier::removeFrontSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    _front.remove(sprite);
}

const std::list<std::shared_ptr<Components::ISprite>> &Unite::Unifier::getFrontSprites() const noexcept {
    return _front;
}

void Unite::Unifier::addObstacle(Obstacles::Obstacle *obstacle) noexcept {
    _obstacles.push_back(std::shared_ptr<Obstacles::Obstacle>(obstacle));
}

void Unite::Unifier::addObstacle(const std::shared_ptr<Obstacles::Obstacle> &obstacle) noexcept {
    _obstacles.push_back(obstacle);
}

void Unite::Unifier::removeObstacle(Obstacles::Obstacle *obstacle) noexcept {
    _obstacles.remove_if([obstacle](const std::shared_ptr<Obstacles::Obstacle> &obstcle) -> bool {
        return obstcle.get() == obstacle;
    });
}

void Unite::Unifier::removeObstacle(const std::shared_ptr<Obstacles::Obstacle> &obstacle) noexcept {
    _obstacles.remove(obstacle);
}

const std::list<std::shared_ptr<Obstacles::Obstacle>> &Unite::Unifier::getObstacles() const noexcept {
    return _obstacles;
}

void Unite::Unifier::addPlayer(Mobs::Player *player) noexcept {
    _players.push_back(std::shared_ptr<Mobs::Player>(player));
}

void Unite::Unifier::addPlayer(const std::shared_ptr<Mobs::Player> &player) noexcept {
    _players.push_back(player);
}

void Unite::Unifier::removePlayer(Mobs::Player *player) noexcept {
    _players.remove_if([player](const std::shared_ptr<Mobs::Player> &plr) -> bool {
        return plr.get() == player;
    });
}

void Unite::Unifier::removePlayer(const std::shared_ptr<Mobs::Player> &player) noexcept {
    _players.remove(player);
}

const std::list<std::shared_ptr<Mobs::Player>> &Unite::Unifier::getPlayers() const noexcept {
    return _players;
}

void Unite::Unifier::addMonster(Mobs::Monster *monster) noexcept {
    _monsters.push_back(std::shared_ptr<Mobs::Monster>(monster));
}

void Unite::Unifier::addMonster(const std::shared_ptr<Mobs::Monster> &monster) noexcept {
    _monsters.push_back(monster);
}

void Unite::Unifier::removeMonster(Mobs::Monster *monster) noexcept {
    _monsters.remove_if([monster](const std::shared_ptr<Mobs::Monster> &mstr) -> bool {
        return mstr.get() == monster;
    });
}

void Unite::Unifier::removeMonster(const std::shared_ptr<Mobs::Monster> &monster) noexcept {
    _monsters.remove(monster);
}

const std::list<std::shared_ptr<Mobs::Monster>> &Unite::Unifier::getMonsters() const noexcept {
    return _monsters;
}

void Unite::Unifier::addEffect(Effects::Effect *effect) noexcept {
    _effects.push_back(std::shared_ptr<Effects::Effect>(effect));
}

void Unite::Unifier::addEffect(const std::shared_ptr<Effects::Effect> &effect) noexcept {
    _effects.push_back(effect);
}

void Unite::Unifier::removeEffect(Effects::Effect *effect) noexcept {
    _effects.remove_if([effect](const std::shared_ptr<Effects::Effect> &effct) -> bool {
        return effct.get() == effect;
    });
}

void Unite::Unifier::removeEffect(const std::shared_ptr<Effects::Effect> &effect) noexcept {
    _effects.remove(effect);
}

const std::list<std::shared_ptr<Effects::Effect>> &Unite::Unifier::getEffects() const noexcept {
    return _effects;
}

void Unite::Unifier::addTrigger(Triggers::Trigger *trigger) noexcept {
    _triggers.push_back(std::shared_ptr<Triggers::Trigger>(trigger));
}

void Unite::Unifier::addTrigger(const std::shared_ptr<Triggers::Trigger> &trigger) noexcept {
    _triggers.push_back(trigger);
}

void Unite::Unifier::removeTrigger(Triggers::Trigger *trigger) noexcept {
    _triggers.remove_if([trigger](const std::shared_ptr<Triggers::Trigger> &trgr) -> bool {
        return trgr.get() == trigger;
    });
}

void Unite::Unifier::removeTrigger(const std::shared_ptr<Triggers::Trigger> &trigger) noexcept {
    _triggers.remove(trigger);
}

const std::list<std::shared_ptr<Triggers::Trigger>> &Unite::Unifier::getTriggers() const noexcept {
    return _triggers;
}
