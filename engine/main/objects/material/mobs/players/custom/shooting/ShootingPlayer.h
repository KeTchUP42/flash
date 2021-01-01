//
// Created by roman on 29.11.2020.
//

#ifndef FLASH_SHOOTINGPLAYER_H
#define FLASH_SHOOTINGPLAYER_H

#include "properties/ShootingPlayerProperties.h"
#include "../jumping/JumpingPlayer.h"
#include "../../../../particles/optimizer/common/ParticleOptimizer.h"

namespace Mobs {

    class ShootingPlayer : public JumpingPlayer {
    public:
        ShootingPlayer(
                const Material::MaterialProperties &material_properties,
                const MobProperties &properties,
                const Components::Area &area,
                const std::shared_ptr<Components::ISpriteBox> &sprite,
                const std::shared_ptr<Material::Algorithms> &algorithms,
                const JumpingPlayerProperties &jumping,
                const ShootingPlayerProperties &shooting,
                Particles::ParticleOptimizer<Particles::Bullet> *optimizer
        );

        void handleEvent(const sf::Event &event, Unite::Unifier *unifier) noexcept override;

    protected:
        Mobs::ShootingPlayerProperties m_shooting;
        std::shared_ptr<Particles::ParticleOptimizer<Particles::Bullet>> m_optimizer;
    };
}

#endif //FLASH_SHOOTINGPLAYER_H
