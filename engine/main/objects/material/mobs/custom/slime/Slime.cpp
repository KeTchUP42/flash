//
// Created by roman on 22.11.2020.
//

#include "Slime.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../../common/reduction/MobsAnalysisReduction.h"
#include "../../../../../../utils/math/algorithms.h"

Mobs::Slime::Slime(
        const Mobs::MobProperties &properties,
        const Components::Area &area,
        const std::shared_ptr<Components::ISpriteBox> &sprite,
        const std::shared_ptr<::Material::Algorithms> &algorithms,
        const SlimeProperties &params
) : BaseMob(properties, area, sprite, algorithms), m_slime(params) {}

Mobs::Slime *Mobs::Slime::createSmallerSlime(const Mobs::MobProperties &properties, const Mobs::SlimeProperties &slimeProperties) const {
    //area
    Components::Size areaSize(m_area.m_size.width / m_slime.splittingCoefficient, m_area.m_size.height / m_slime.splittingCoefficient);
    Components::Area area(
            Components::Point(m_area.m_point.x + (m_area.m_size.width - areaSize.width) / 2,
                              m_area.m_point.y + (m_area.m_size.height - areaSize.height) / 2),
            areaSize, m_area.m_angle);
    //sprite
    Components::Size spriteSize(m_sprite->getArea().m_size.width / m_slime.splittingCoefficient, m_sprite->getArea().m_size.height / m_slime.splittingCoefficient);
    Components::Area spriteArea(
            Components::Point(m_sprite->getArea().m_point.x + (m_sprite->getArea().m_size.width - spriteSize.width) / 2,
                              m_sprite->getArea().m_point.y + (m_sprite->getArea().m_size.height - spriteSize.height) / 2),
            spriteSize, m_sprite->getArea().m_angle);

    std::shared_ptr<Components::ISpriteBox> spriteBox = std::make_shared<Components::SpriteBox>(spriteArea, m_sprite->getTexture());
    //algo
    std::pair<float, float> step = m_algorithms->getCollision().getMovingCollision().getAnalysisStep();
    float stepX = step.first / m_slime.splittingCoefficient > 1 ? step.first / m_slime.splittingCoefficient : 1;
    float stepY = step.second / m_slime.splittingCoefficient > 1 ? step.second / m_slime.splittingCoefficient : 1;

    std::shared_ptr<Material::Algorithms> algo = std::make_shared<Material::Algorithms>(
            std::make_shared<Material::Collision>(stepX, stepY));

    return new Slime(properties, area, spriteBox, algo, slimeProperties);
}

void Mobs::Slime::selfAction(Unite::Unifier *unifier) {
    RD::healthAnalysis(*this);
    if (this->isDead()) {
        //Size checking.
        bool isValidSize = ((m_sprite->getArea().m_size.width / m_slime.splittingCoefficient >= m_slime.minSplitSize) &&
                            (m_sprite->getArea().m_size.height / m_slime.splittingCoefficient >= m_slime.minSplitSize));

        if (isValidSize && ((m_sprite->getArea().m_size.width / m_slime.splittingCoefficient >= Components::SpriteBox::MIN_SPRITE_SIDE_SIZE) &&
                            (m_sprite->getArea().m_size.height / m_slime.splittingCoefficient >= Components::SpriteBox::MIN_SPRITE_SIDE_SIZE))) {

            unifier->addFrameAction([this](Unite::Unifier *unifier1) -> void {
                //Slime properties
                float punchPower = m_slime.punchPower / m_slime.splittingCoefficient;
                float punchDamage = m_slime.punchDamage / m_slime.splittingCoefficient;
                SlimeProperties slimeProperties(
                        m_slime.moveSpeed,
                        m_slime.jumpSpeed,
                        m_slime.jumpRateCoefficient,
                        (punchPower > 1) ? punchPower : 1,
                        (punchDamage > 0) ? punchDamage : 0,
                        m_slime.elasticCoefficient,
                        m_slime.frictionCoefficient,
                        m_slime.minSplitSize,
                        m_slime.splittingCoefficient,
                        m_slime.splitSlimesNumber);

                int healthPoints = m_properties.maxHealthPoints / m_slime.splittingCoefficient;
                if (healthPoints == 0) healthPoints = 1;

                //todo: Thick about speed coeffs in object engine config block.
                //todo: Think of a way to calculate the speed coefficient.
                //Calculating base slimes speed.
                float xSpeedOffset = m_area.m_size.width / 20;
                float ySpeedOffset = m_area.m_size.height / 10;

                for (size_t i = 0; i < m_slime.splitSlimesNumber; ++i) {
                    short destination = ((i % 2 == 0) ? -1 : 1);
                    unifier1->addStandAloneMob(this->createSmallerSlime(MobProperties(
                            Components::Speed(m_properties.speed.xSpeed + (destination * Computations::random(0, 5) + destination * xSpeedOffset),
                                              m_properties.speed.ySpeed - (Computations::random(0, 5) + ySpeedOffset)),
                            healthPoints, healthPoints), slimeProperties));
                }
            });
        }
        unifier->addFrameAction([this](Unite::Unifier *unifier1) -> void {
            unifier1->removeStandAloneMob(this);
        });

    } else {

        //Players jumping
        for (Mobs::Player *player : unifier->getPlayers()) {
            if ((player->getPosition().y < this->getPosition().y) && m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(player, this)) {
                this->prejudice(static_cast<int>(player->getSpeed().ySpeed / 4)); //Calculating damage from speed.
                bool sameSign = player->getSpeed().ySpeed * this->getSpeed().ySpeed >= 0;
                float ySpeed = static_cast<int>(-1 * player->getSpeed().ySpeed * m_slime.elasticCoefficient + (sameSign ? 0 : this->getSpeed().ySpeed));
                player->setYSpeed((std::abs(ySpeed) == 1) ? 0 : ySpeed);
                if (player->getSpeed().xSpeed != this->getSpeed().xSpeed) {
                    player->setXSpeed(static_cast<int>(player->getSpeed().xSpeed * m_slime.frictionCoefficient));
                }
            }
        }

        //Slime punch
        Mobs::Player *player;
        if ((player = m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getPlayers())) != nullptr) {
            player->prejudice(m_slime.punchDamage);
            if (this->getSpeed().xSpeed * player->getSpeed().xSpeed <= 0) {
                player->setSpeed(Components::Speed((this->getSpeed().xSpeed > 0 ? 1 : -1) * m_slime.punchPower, -1 * m_slime.punchPower * 2));
            }
        }

        Obstacles::Block *block;
        if ((block = m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(this, unifier->getBlocks())) != nullptr) {
            //Slime moving
            if ((Computations::random(0, m_slime.jumpRateCoefficient) == 0) && (this->getPosition().y < block->getPosition().y) &&
                (static_cast<int>(this->getSpeed().ySpeed) == 0)) {
                this->addSpeed(((Computations::random(0, 1) == 1) ? 1 : -1) * m_slime.moveSpeed, -1 * m_slime.jumpSpeed);
            } else {
                bool sameSign = m_properties.speed.ySpeed * block->getSpeed().ySpeed >= 0;
                float ySpeed = static_cast<int>(-1 * m_properties.speed.ySpeed * block->getProperties().elasticCoefficient + (sameSign ? 0 : block->getSpeed().ySpeed));
                m_properties.speed.ySpeed = (std::abs(ySpeed) == 1) ? 0 : ySpeed;
                if (m_properties.speed.xSpeed != block->getSpeed().xSpeed) {
                    m_properties.speed.xSpeed = static_cast<int>(m_properties.speed.xSpeed * block->getProperties().frictionCoefficient);
                }
            }
        }

        if ((block = m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getBlocks())) != nullptr) {
            bool sameSign = m_properties.speed.xSpeed * block->getSpeed().xSpeed >= 0;
            float xSpeed = static_cast<int>(-1 * m_properties.speed.xSpeed * block->getProperties().elasticCoefficient + (sameSign ? 0 : block->getSpeed().xSpeed));
            m_properties.speed.xSpeed = (std::abs(xSpeed) == 1) ? 0 : xSpeed;
            if (m_properties.speed.ySpeed != block->getSpeed().ySpeed) {
                m_properties.speed.ySpeed = static_cast<int>(m_properties.speed.ySpeed * block->getProperties().frictionCoefficient);
            }
        }
    }
}
