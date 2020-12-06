//
// Created by roman on 29.11.2020.
//

#include "ShootingPlayer.h"
#include "../../../../particles/bullets/custom/sprite-visible/player/PlayerTexturedBullet.h"
#include "../../../../../auxiliary/components/sprite/primitive/SpriteBox.h"

Mobs::ShootingPlayer::ShootingPlayer(
        const Material::MaterialProperties &material_properties,
        const Mobs::MobProperties &properties,
        const Components::Area &area,
        const std::shared_ptr<Components::ISpriteBox> &sprite,
        const std::shared_ptr<Material::Algorithms> &algorithms,
        const Mobs::JumpingPlayerProperties &jumping,
        const Mobs::ShootingPlayerProperties &shooting,
        Particles::ParticleOptimizer<Particles::Bullet> *optimizer
) : JumpingPlayer(material_properties, properties, area, sprite, algorithms, jumping), m_shooting(shooting), m_optimizer(optimizer) {}

static Components::Point bulletPointCalculating(const Mobs::Player &player, const Components::Size &bulletSize, bool right) noexcept {
    Components::Point min = Material::minCoordinates(player);
    Components::Point max = Material::maxCoordinates(player);
    return Components::Point(
            ((min.x + max.x) / 2) + (right ? 1 : -1) * ((max.x - min.x) / 2) - bulletSize.width / 2,
            ((min.y + max.y) / 2) - bulletSize.height / 2
    );
}

void Mobs::ShootingPlayer::handleEvent(const sf::Event &event, Unite::Unifier *unifier) noexcept {
    JumpingPlayer::handleEvent(event, unifier);

    if (event.type == sf::Event::KeyReleased) {

        if (event.key.code == m_keyMap[KeyAlias::ShootRight]) {
            Components::Point point = bulletPointCalculating(*this, m_shooting.bulletsData.size, true);
            Components::Point spritePoint(
                    point.x - ((m_shooting.bulletsSpriteData.size.width - m_shooting.bulletsData.size.width) / 2),
                    point.y - ((m_shooting.bulletsSpriteData.size.height - m_shooting.bulletsData.size.height) / 2)
            );

            unifier->addBullet(new Particles::PlayerTexturedBullet(
                    Material::MaterialProperties(Components::Speed(m_shooting.bulletsFlightSpeed, 0)),
                    Particles::ParticleProperties(m_shooting.bulletsUnderEffects),
                    Particles::BulletProperties(m_shooting.bulletsDamage),
                    Components::Area(point, m_shooting.bulletsData.size, m_shooting.bulletsData.angle),
                    std::make_shared<Material::Algorithms>(std::make_shared<Material::Collision>(1, 1)),
                    std::make_shared<Components::SpriteBox>(
                            Components::Area(spritePoint, m_shooting.bulletsSpriteData.size, m_shooting.bulletsSpriteData.angle),
                            m_shooting.rightBulletsTexture), m_optimizer
            ));
        }

        if (event.key.code == m_keyMap[KeyAlias::ShootLeft]) {
            Components::Point point = bulletPointCalculating(*this, m_shooting.bulletsData.size, false);
            Components::Point spritePoint(
                    point.x - ((m_shooting.bulletsSpriteData.size.width - m_shooting.bulletsData.size.width) / 2),
                    point.y - ((m_shooting.bulletsSpriteData.size.height - m_shooting.bulletsData.size.height) / 2)
            );

            unifier->addBullet(new Particles::PlayerTexturedBullet(
                    Material::MaterialProperties(Components::Speed(-m_shooting.bulletsFlightSpeed, 0)),
                    Particles::ParticleProperties(m_shooting.bulletsUnderEffects),
                    Particles::BulletProperties(m_shooting.bulletsDamage),
                    Components::Area(point, m_shooting.bulletsData.size, m_shooting.bulletsData.angle),
                    std::make_shared<Material::Algorithms>(std::make_shared<Material::Collision>(1, 1)),
                    std::make_shared<Components::SpriteBox>(
                            Components::Area(spritePoint, m_shooting.bulletsSpriteData.size, m_shooting.bulletsSpriteData.angle),
                            m_shooting.leftBulletsTexture), m_optimizer
            ));
        }
    }
}
