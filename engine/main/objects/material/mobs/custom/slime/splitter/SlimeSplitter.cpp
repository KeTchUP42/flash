//
// Created by roman on 25.11.2020.
//

#include "SlimeSplitter.h"
#include "../../../../../auxiliary/components/sprite/primitive/SpriteBox.h"

Mobs::SlimeSplitter::SlimeSplitter(float splittingCoefficient) : m_splittingCoefficient(splittingCoefficient) {}

Mobs::Slime *Mobs::SlimeSplitter::split(Mobs::Slime &slime, const Mobs::MobProperties &properties, const Mobs::SlimeProperties &slimeProperties) const {
    //area
    Components::Size areaSize(slime.getSize().width / m_splittingCoefficient, slime.getSize().height / m_splittingCoefficient);
    Components::Area area(
            Components::Point(slime.getPosition().x + (slime.getSize().width - areaSize.width) / 2,
                              slime.getPosition().y + (slime.getSize().height - areaSize.height) / 2),
            areaSize, slime.getRotation());
    //sprite
    Components::Size spriteSize(slime.getSprite()->getArea().m_size.width / m_splittingCoefficient, slime.getSprite()->getArea().m_size.height / m_splittingCoefficient);
    Components::Area spriteArea(
            Components::Point(slime.getSprite()->getArea().m_point.x + (slime.getSprite()->getArea().m_size.width - spriteSize.width) / 2,
                              slime.getSprite()->getArea().m_point.y + (slime.getSprite()->getArea().m_size.height - spriteSize.height) / 2),
            spriteSize, slime.getSprite()->getArea().m_angle);

    std::shared_ptr<Components::ISpriteBox> spriteBox = std::make_shared<Components::SpriteBox>(spriteArea, slime.getSprite()->getTexture());
    //algo
    std::pair<float, float> step = slime.getAlgorithms()->getCollision().getMovingCollision().getAnalysisStep();
    float stepX = step.first / m_splittingCoefficient > 1 ? step.first / m_splittingCoefficient : 1;
    float stepY = step.second / m_splittingCoefficient > 1 ? step.second / m_splittingCoefficient : 1;

    std::shared_ptr<Material::Algorithms> algo = std::make_shared<Material::Algorithms>(
            std::make_shared<Material::Collision>(stepX, stepY));

    return new Slime(properties, area, spriteBox, algo, slimeProperties);
}

Mobs::Slime *Mobs::SlimeSplitter::split(Mobs::Slime &slime, const std::function<Mobs::MobProperties()> &properties,
                                        const std::function<Mobs::SlimeProperties()> &slimeProperties) const {
    return this->split(slime, properties(), slimeProperties());
}
