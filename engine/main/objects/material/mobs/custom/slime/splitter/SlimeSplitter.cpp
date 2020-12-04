//
// Created by roman on 25.11.2020.
//

#include "SlimeSplitter.h"

Mobs::SlimeSplitter::SlimeSplitter(float splittingCoefficient) : m_splittingCoefficient(splittingCoefficient) {}

Mobs::Slime *Mobs::SlimeSplitter::split(Mobs::Slime &slime, const SlimeProperties &properties) const {
    return new Slime(
            properties.material_properties,
            properties.mob_properties,
            this->splitSlimeArea(slime),
            this->splitSlimeSprite(slime),
            this->splitSlimeAlgorithms(slime),
            properties.slime_properties
    );
}

Components::Area Mobs::SlimeSplitter::splitSlimeArea(Mobs::Slime &slime) const noexcept {
    unsigned int area_width = slime.getSize().width;
    unsigned int area_height = slime.getSize().height;

    Components::Size size(area_width / m_splittingCoefficient, area_height / m_splittingCoefficient);
    Components::Point point(slime.getPosition().x + (area_width - size.width) / 2,
                            slime.getPosition().y + (area_height - size.height) / 2);
    return Components::Area(point, size, slime.getRotation());
}

std::shared_ptr<Components::ISpriteBox> Mobs::SlimeSplitter::splitSlimeSprite(Mobs::Slime &slime) const noexcept {
    unsigned int sprite_width = slime.getSprite()->getArea().m_size.width;
    unsigned int sprite_height = slime.getSprite()->getArea().m_size.height;

    Components::Size size(sprite_width / m_splittingCoefficient, sprite_height / m_splittingCoefficient);
    Components::Point point(slime.getSprite()->getArea().m_point.x + (sprite_width - size.width) / 2,
                            slime.getSprite()->getArea().m_point.y + (sprite_height - size.height) / 2);
    Components::Area area(point, size, slime.getSprite()->getArea().m_angle);
    return std::make_shared<Components::SpriteBox>(area, slime.getSprite()->getTexture());
}

std::shared_ptr<Material::Algorithms> Mobs::SlimeSplitter::splitSlimeAlgorithms(Mobs::Slime &slime) const noexcept {
    std::pair<float, float> step = slime.getAlgorithms()->getCollision().getMovingCollision().getAnalysisStep();
    float stepX = step.first / m_splittingCoefficient;
    if (stepX < 1) stepX = 1;
    float stepY = step.second / m_splittingCoefficient;
    if (stepY < 1) stepY = 1;
    return std::make_shared<Material::Algorithms>(std::make_shared<Material::Collision>(stepX, stepY));
}

Mobs::SlimeProperties Mobs::SlimeSplitter::splitSlimeProperties(const Mobs::SlimeProperties &properties) const noexcept {
    return Mobs::SlimeProperties(
            properties.moveSpeed,
            properties.jumpSpeed,
            properties.jumpRateCoefficient,
            std::round(properties.punchPower / m_splittingCoefficient),
            std::round(properties.punchDamage / m_splittingCoefficient),
            properties.elasticCoefficient,
            properties.frictionCoefficient,
            properties.minSplitSize,
            m_splittingCoefficient,
            properties.splitSlimesNumber,
            std::pair<float, float>(
                    properties.splitPower.first / m_splittingCoefficient,
                    properties.splitPower.second / m_splittingCoefficient
            ));
}
