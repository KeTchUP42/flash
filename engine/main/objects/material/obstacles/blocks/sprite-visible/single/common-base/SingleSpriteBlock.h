//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_SINGLESPRITEBLOCK_H
#define FLASH_SINGLESPRITEBLOCK_H

#include "../../../../common/Obstacle.h"
#include "../../../../../../auxiliary/components/sprite/primitive/ISpriteBox.h"
#include "../../../../../common/algorithms/Algorithms.h"

namespace Obstacles {

    class SingleSpriteBlock : public Obstacles::Obstacle {
    public:
        explicit SingleSpriteBlock(const ObstacleProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite,
                                   const std::shared_ptr<Material::Algorithms> &algorithms);

        /**
         * @brief Method changes block's sprite texture.
         * @param texture New texture.
         */
        void loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept;

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

        void rotate(float angle) noexcept override;

        void rotate(float angle, float x, float y) noexcept override;

        void rotate(float angle, const Components::Point &point) noexcept override;

        const Components::Point &getPosition() const noexcept override;

        const Components::Size &getSize() const noexcept override;

        float getRotation() const noexcept override;

        void setPosition(const Components::Point &point) noexcept override;

        void setPosition(float x, float y) noexcept override;

        void setSize(const Components::Size &size) noexcept override;

        void setRotation(float angle) noexcept override;

        virtual ~SingleSpriteBlock() = default;

    protected:
        std::shared_ptr<Components::ISpriteBox> m_sprite;
        std::shared_ptr<Material::Algorithms> m_algorithms;
    };
}

#endif //FLASH_SINGLESPRITEBLOCK_H
