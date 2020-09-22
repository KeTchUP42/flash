//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_SINGLESPRITEBLOCK_H
#define FLASH_SINGLESPRITEBLOCK_H

#include "../../../common/Obstacle.h"
#include "../../../../../auxiliary/components/sprite/common/box/ISpriteBox.h"

namespace Obstacles {

    class SingleSpriteBlock : public Obstacles::Obstacle {
    public:
        /**
         * @brief Base block constructor.
         * @param sprite Block's sprite.
         */
        explicit SingleSpriteBlock(const std::shared_ptr<Components::ISpriteBox> &sprite);

        /**
         * @brief Method changes block's sprite texture.
         * @param texture New texture.
         */
        void loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept;

        bool collision(float x, float y) const noexcept override;

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

        void rotate(float angle) noexcept override;

        void rotate(float angle, float x, float y) noexcept override;

        void rotate(float angle, const Components::Point &point) noexcept override;

        void addSpeed(float offsetX, float offsetY) noexcept override;

        void setMoveSpeed(const Components::Speed &speed) noexcept override;

        const Components::Speed &getMoveSpeed() const noexcept override;

        const Components::Point &getPosition() const noexcept override;

        const Components::Size &getSize() const noexcept override;

        float getRotation() const noexcept override;

        void setPosition(const Components::Point &point) noexcept override;

        void setPosition(float x, float y) noexcept override;

        void setSize(const Components::Size &size) noexcept override;

        void setRotation(float angle) noexcept override;

        virtual ~SingleSpriteBlock() = default;

    protected:
        Components::Speed _speed;
        std::shared_ptr<Components::ISpriteBox> _sprite;
    };
}

#endif //FLASH_SINGLESPRITEBLOCK_H
