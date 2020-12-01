//
// Created by roman on 29.11.2020.
//

#include "PlayerTexturedBullet.h"
#include "../../../../../reduction/collision/CollisionReduction.h"

Particles::PlayerTexturedBullet::PlayerTexturedBullet(
        const Material::MaterialProperties &material_properties,
        const Particles::ParticleProperties &properties,
        const Particles::BulletProperties &bullet,
        const Components::Area &area,
        const std::shared_ptr<Material::Algorithms> &algorithms,
        const std::shared_ptr<Components::ISpriteBox> &sprite,
        const std::shared_ptr<ParticleOptimizer<Bullet>> &optimizer
) : TexturedBullet(material_properties, properties, bullet, area, algorithms, sprite, optimizer) {}

void Particles::PlayerTexturedBullet::selfAction(Unite::Unifier *unifier) {
    RD::abscissaBlocksNaturalCollision(this, *m_algorithms.get(), unifier);
    RD::ordinateBlocksNaturalCollision(this, *m_algorithms.get(), unifier);
    m_optimizer->optimize(this, *unifier);

    Mobs::Mob *mob;
    if ((mob = m_algorithms->getCollision().getStaticCollision().staticMoveAble(this, unifier->getStandAloneMobs())) != nullptr) {
        mob->dealDamage(m_bullet.damage);
        unifier->addFrameAction([this](Unite::Unifier *unifier1) -> void {
            unifier1->removeBullet(this);
        });
    }
}
