//
// Created by roman on 30.11.2020.
//

#include "BulletsOptimizer.h"
#include "../../../common/collision/algorithms/coordinates/CoordinatesCalculation.h"

Particles::BulletsOptimizer::BulletsOptimizer(const sf::Vector2<unsigned int> &windowSize) : m_window_size(windowSize) {}

bool Particles::BulletsOptimizer::optimize(Particles::Bullet *particle, Unite::Unifier &unifier) {
    if (particle->getSpeed().isZero()) {
        unifier.addFrameAction([particle](Unite::Unifier *unifier1) -> void {
            unifier1->removeBullet(particle);
        });
        return true;
    }

    Components::Point min = Material::minCoordinates(*particle);
    Components::Point max = Material::maxCoordinates(*particle);

    if (((max.x < 0) || (min.x > m_window_size.x)) || ((max.y < 0) || (min.y > m_window_size.y))) {

        unifier.addFrameAction([particle](Unite::Unifier *unifier1) -> void {
            unifier1->removeBullet(particle);
        });
        return true;
    }
    return false;
}