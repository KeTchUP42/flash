//
// Created by roman on 29.11.2020.
//

#ifndef FLASH_BULLET_H
#define FLASH_BULLET_H

#include "../../../../../auxiliary/components/elementary/area/Area.h"
#include "../properties/BulletProperties.h"
#include "../../../common/Particle.h"

namespace Particles {

    class Bullet : public Particle {
    public:
        explicit Bullet(
                const ParticleProperties &properties,
                const BulletProperties &bullet,
                const Components::Area &area
        );

        virtual ~Bullet() = default;

    protected:
        BulletProperties m_bullet;
    };
}

#endif //FLASH_BULLET_H
