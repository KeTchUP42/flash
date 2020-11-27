//
// Created by roman on 25.11.2020.
//

#include "MobsCollisionReduction.h"

void Mobs::RD::ordinateBlocksNaturalCollision(Mobs::Mob *mob, Material::Algorithms &algorithms, Unite::Unifier *unifier) noexcept {
    Obstacles::Block *block;
    if ((block = algorithms.getCollision().getMovingCollision().ordinateMoveAble(mob, unifier->getBlocks())) != nullptr) {
        bool sameSign = mob->getSpeed().ySpeed * block->getSpeed().ySpeed >= 0;
        float ySpeed = static_cast<int>(-1 * mob->getSpeed().ySpeed * block->getProperties().elasticCoefficient + (sameSign ? 0 : block->getSpeed().ySpeed));
        mob->setYSpeed((std::abs(ySpeed) == 1) ? 0 : ySpeed);
        if (mob->getSpeed().xSpeed != block->getSpeed().xSpeed) {
            mob->setXSpeed(static_cast<int>(mob->getSpeed().xSpeed * block->getProperties().frictionCoefficient));
        }
    }
}

void Mobs::RD::abscissaBlocksNaturalCollision(Mobs::Mob *mob, Material::Algorithms &algorithms, Unite::Unifier *unifier) noexcept {
    Obstacles::Block *block;
    if ((block = algorithms.getCollision().getMovingCollision().abscissaMoveAble(mob, unifier->getBlocks())) != nullptr) {
        bool sameSign = mob->getSpeed().xSpeed * block->getSpeed().xSpeed >= 0;
        float xSpeed = static_cast<int>(-1 * mob->getSpeed().xSpeed * block->getProperties().elasticCoefficient + (sameSign ? 0 : block->getSpeed().xSpeed));
        mob->setXSpeed((std::abs(xSpeed) == 1) ? 0 : xSpeed);
        if (mob->getSpeed().ySpeed != block->getSpeed().ySpeed) {
            mob->setYSpeed(static_cast<int>(mob->getSpeed().ySpeed * block->getProperties().frictionCoefficient));
        }
    }
}
