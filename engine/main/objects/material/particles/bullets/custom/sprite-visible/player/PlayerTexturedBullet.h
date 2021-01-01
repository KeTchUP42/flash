//
// Created by roman on 29.11.2020.
//

#ifndef FLASH_PLAYERTEXTUREDBULLET_H
#define FLASH_PLAYERTEXTUREDBULLET_H

#include "../common/TexturedBullet.h"

namespace Particles {

    class PlayerTexturedBullet : public TexturedBullet {
    public:
        PlayerTexturedBullet(
                const Material::MaterialProperties &material_properties,
                const ParticleProperties &properties,
                const BulletProperties &bullet,
                const Components::Area &area,
                const std::shared_ptr<Material::Algorithms> &algorithms,
                const std::shared_ptr<Components::ISpriteBox> &sprite,
                const std::shared_ptr<ParticleOptimizer<Bullet>> &optimizer
        );

        void selfAction(Unite::Unifier *unifier) override;
    };
}

#endif //FLASH_PLAYERTEXTUREDBULLET_H
