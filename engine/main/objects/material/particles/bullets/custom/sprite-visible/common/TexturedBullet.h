//
// Created by roman on 29.11.2020.
//

#ifndef FLASH_TEXTUREDBULLET_H
#define FLASH_TEXTUREDBULLET_H

#include "../../../common/base/AnalyzingBullet.h"
#include "../../../../optimizer/common/ParticleOptimizer.h"

namespace Particles {

    class TexturedBullet : public AnalyzingBullet {
    public:
        TexturedBullet(
                const Material::MaterialProperties &material_properties,
                const ParticleProperties &properties,
                const BulletProperties &bullet,
                const Components::Area &area,
                const std::shared_ptr<Material::Algorithms> &algorithms,
                const std::shared_ptr<Components::ISpriteBox> &sprite,
                const std::shared_ptr<ParticleOptimizer<Bullet>> &optimizer
        );

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

    protected:
        std::shared_ptr<Components::ISpriteBox> m_sprite;
        std::shared_ptr<ParticleOptimizer<Bullet>> m_optimizer;
    };
}

#endif //FLASH_TEXTUREDBULLET_H
