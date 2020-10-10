//
// Created by roman on 06.10.2020.
//

#ifndef FLASH_INVISIBLEBLOCK_H
#define FLASH_INVISIBLEBLOCK_H

#include "../../../common/Obstacle.h"
#include "../../../../../auxiliary/components/elementary/area/Area.h"
#include "../../../../common/algorithms/Algorithms.h"

namespace Obstacles {

    class InvisibleBlock : public Obstacle {
    public:
        explicit InvisibleBlock(const ObstacleProperties &properties, const Components::Area &area,
                                const std::shared_ptr<Material::Algorithms> &algorithms);

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

        const ObstacleProperties &getProperties() const noexcept override;

        const Components::Point &getPosition() const noexcept override;

        const Components::Size &getSize() const noexcept override;

        float getRotation() const noexcept override;

        void setPosition(const Components::Point &point) noexcept override;

        void setPosition(float x, float y) noexcept override;

        void setSize(const Components::Size &size) noexcept override;

        void setRotation(float angle) noexcept override;

        void rotate(float angle) noexcept override;

        void rotate(float angle, float x, float y) noexcept override;

        void rotate(float angle, const Components::Point &point) noexcept override;

        void addSpeed(float offsetX, float offsetY) noexcept override;

        void setSpeed(const Components::Speed &speed) noexcept override;

        const Components::Speed &getSpeed() const noexcept override;

    protected:
        Components::Area m_area;
        std::shared_ptr<Material::Algorithms> m_algorithms;
    };
}

#endif //FLASH_INVISIBLEBLOCK_H
