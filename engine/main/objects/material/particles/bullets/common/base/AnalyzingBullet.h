//
// Created by roman on 29.11.2020.
//

#ifndef FLASH_ANALYZINGBULLET_H
#define FLASH_ANALYZINGBULLET_H

#include "Bullet.h"
#include "../../../../common/algorithms/Algorithms.h"

namespace Particles {

    class AnalyzingBullet : public Bullet {
    public:
        explicit AnalyzingBullet(
                const ParticleProperties &properties,
                const BulletProperties &bullet,
                const Components::Area &area,
                const std::shared_ptr<Material::Algorithms> &algorithms
        ) : Bullet(properties, bullet, area), m_algorithms(algorithms) {}

    protected:
        std::shared_ptr<Material::Algorithms> m_algorithms;
    };
}

#endif //FLASH_ANALYZINGBULLET_H
