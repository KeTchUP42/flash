//
// Created by roman on 30.11.2020.
//

#ifndef FLASH_BULLETSOPTIMIZER_H
#define FLASH_BULLETSOPTIMIZER_H

#include "../common/ParticleOptimizer.h"
#include "../../bullets/common/base/Bullet.h"

namespace Particles {

    class BulletsOptimizer : public ParticleOptimizer<Particles::Bullet> {
    public:
        explicit BulletsOptimizer(const sf::Vector2<unsigned int> &windowSize);

        bool optimize(Bullet *particle, Unite::Unifier &unifier) override;

    private:
        sf::Vector2<unsigned int> m_window_size;
    };
}

#endif //FLASH_BULLETSOPTIMIZER_H
