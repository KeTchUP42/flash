//
// Created by roman on 29.11.2020.
//

#include "Bullet.h"
#include "../../../../../auxiliary/computations/CoordinatesComputations.h"

Particles::Bullet::Bullet(
        const Particles::ParticleProperties &properties,
        const Particles::BulletProperties &bullet,
        const Components::Area &area
) : Particle(properties, Computations::coordinates(const_cast<Components::Area &>(area))), m_bullet(bullet) {}
