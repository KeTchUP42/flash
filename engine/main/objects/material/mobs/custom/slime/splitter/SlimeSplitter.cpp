//
// Created by roman on 25.11.2020.
//

#include "SlimeSplitter.h"

Mobs::SlimeSplitter::SlimeSplitter(float splittingCoefficient) : SPLITTING_COEFFICIENT(splittingCoefficient) {}

Components::Area Mobs::SlimeSplitter::splitArea(const Mobs::Slime &slime) const noexcept {
    unsigned int area_width = slime.getSize().width;
    unsigned int area_height = slime.getSize().height;

    Components::Size size(area_width / SPLITTING_COEFFICIENT, area_height / SPLITTING_COEFFICIENT);
    Components::Point point(slime.getPosition().x + (area_width - size.width) / 2,
                            slime.getPosition().y + (area_height - size.height) / 2);
    return Components::Area(point, size, slime.getRotation());
}

std::shared_ptr<Components::ISpriteBox> Mobs::SlimeSplitter::splitSprite(const Mobs::Slime &slime) const noexcept {
    unsigned int sprite_width = slime.getSprite()->getArea().m_size.width;
    unsigned int sprite_height = slime.getSprite()->getArea().m_size.height;

    Components::Size size(sprite_width / SPLITTING_COEFFICIENT, sprite_height / SPLITTING_COEFFICIENT);
    Components::Point point(slime.getSprite()->getArea().m_point.x + (sprite_width - size.width) / 2,
                            slime.getSprite()->getArea().m_point.y + (sprite_height - size.height) / 2);
    Components::Area area(point, size, slime.getSprite()->getArea().m_angle);
    return std::make_shared<Components::SpriteBox>(area, slime.getSprite()->getTexture());
}

std::shared_ptr<Material::Algorithms> Mobs::SlimeSplitter::splitAlgorithms(const Mobs::Slime &slime) const noexcept {
    std::pair<float, float> step = slime.getAlgorithms()->getCollision().getMovingCollision().getAnalysisStep();
    float stepX = step.first / SPLITTING_COEFFICIENT;
    float stepY = step.second / SPLITTING_COEFFICIENT;
    return std::make_shared<Material::Algorithms>(Material::AlgorithmsParameters((stepX < 1) ? 1 : stepX, (stepY < 1) ? 1 : stepY));
}

Mobs::SlimeProperties Mobs::SlimeSplitter::splitProperties(const Mobs::SlimeProperties &properties) const noexcept {
    return Mobs::SlimeProperties(
            properties.moveSpeed,
            properties.jumpSpeed,
            properties.jumpRateCoefficient,
            std::round(properties.punchPower / SPLITTING_COEFFICIENT),
            std::round(properties.punchDamage / SPLITTING_COEFFICIENT),
            properties.elasticCoefficient,
            properties.frictionCoefficient,
            properties.minSplitSize,
            SPLITTING_COEFFICIENT,
            properties.splitSlimesNumber,
            std::pair<float, float>(
                    properties.splitPower.first / SPLITTING_COEFFICIENT,
                    properties.splitPower.second / SPLITTING_COEFFICIENT
            ));
}

std::shared_ptr<Mobs::Slime> Mobs::split(const Mobs::SlimeSplitter &splitter, const Mobs::Slime &slime, const Mobs::SlimeMobProperties &properties) {
    return std::make_shared<Slime>(
            properties.material_properties,
            properties.mob_properties,
            splitter.splitArea(slime),
            splitter.splitSprite(slime),
            splitter.splitAlgorithms(slime),
            properties.slime_properties
    );
}