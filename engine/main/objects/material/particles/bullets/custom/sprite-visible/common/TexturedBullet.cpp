//
// Created by roman on 29.11.2020.
//

#include "TexturedBullet.h"

Particles::TexturedBullet::TexturedBullet(
        const Material::MaterialProperties &material_properties,
        const Particles::ParticleProperties &properties,
        const Particles::BulletProperties &bullet,
        const Components::Area &area,
        const std::shared_ptr<Material::Algorithms> &algorithms,
        const std::shared_ptr<Components::ISpriteBox> &sprite,
        const std::shared_ptr<ParticleOptimizer<Bullet>> &optimizer
) : AnalyzingBullet(material_properties, properties, bullet, area, algorithms), m_sprite(sprite), m_optimizer(optimizer) {}

void Particles::TexturedBullet::draw(sf::RenderTarget &target) const noexcept {
    m_sprite->draw(target);
}

void Particles::TexturedBullet::move(float offsetX, float offsetY) noexcept {
    MaterialObject::move(offsetX, offsetY);
    m_sprite->move(offsetX, offsetY);
}
