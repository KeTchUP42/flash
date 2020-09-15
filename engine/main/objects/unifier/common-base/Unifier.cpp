//
// Created by roman on 09.09.2020.
//

#include "Unifier.h"

void Unite::Unifier::addBackSprite(Components::ISprite *sprite) noexcept {
    _backSprites.push_back(std::shared_ptr<Components::ISprite>(sprite));
}

void Unite::Unifier::addBackSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    _backSprites.push_back(sprite);
}

void Unite::Unifier::removeBackSprite(Components::ISprite *sprite) noexcept {
    _backSprites.remove_if([sprite](const std::shared_ptr<Components::ISprite> &sprt) -> bool {
        return sprt.get() == sprite;
    });
}

void Unite::Unifier::removeBackSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    _backSprites.remove(sprite);
}

const std::list<std::shared_ptr<Components::ISprite>> &Unite::Unifier::getBackSprites() const noexcept {
    return _backSprites;
}

void Unite::Unifier::addFrontSprite(Components::ISprite *sprite) noexcept {
    _frontSprites.push_back(std::shared_ptr<Components::ISprite>(sprite));
}

void Unite::Unifier::addFrontSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    _frontSprites.push_back(sprite);
}

void Unite::Unifier::removeFrontSprite(Components::ISprite *sprite) noexcept {
    _frontSprites.remove_if([sprite](const std::shared_ptr<Components::ISprite> &sprt) -> bool {
        return sprt.get() == sprite;
    });
}

void Unite::Unifier::removeFrontSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    _frontSprites.remove(sprite);
}

const std::list<std::shared_ptr<Components::ISprite>> &Unite::Unifier::getFrontSprites() const noexcept {
    return _frontSprites;
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
