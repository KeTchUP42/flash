//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_SINGLESPRITEBLOCK_H
#define FLASH_SINGLESPRITEBLOCK_H

#include "../../../common/BaseBlock.h"
#include "../../../../../../auxiliary/components/sprite/primitive/ISpriteBox.h"

namespace Obstacles {

    class SingleSpriteBlock : public BaseBlock {
    public:
        explicit SingleSpriteBlock(
                const ObstacleProperties &properties,
                const std::shared_ptr<Components::ISpriteBox> &sprite,
                const std::shared_ptr<Material::Algorithms> &algorithms
        );

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

        void setPosition(const Components::Point &point) noexcept override;

        void setPosition(float x, float y) noexcept override;

        void setSize(const Components::Size &size) noexcept override;

        void setRotation(float angle) noexcept override;

        virtual ~SingleSpriteBlock() = default;

    protected:
        std::shared_ptr<Components::ISpriteBox> m_sprite;
    };
}

#endif //FLASH_SINGLESPRITEBLOCK_H
