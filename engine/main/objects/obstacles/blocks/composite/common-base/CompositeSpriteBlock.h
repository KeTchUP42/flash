//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_COMPOSITESPRITEBLOCK_H
#define FLASH_COMPOSITESPRITEBLOCK_H

#include "../../../shared/Obstacle.h"

namespace Obstacles {

    class CompositeSpriteBlock : public Obstacles::Obstacle {
    public:
        /**
         * @brief Base constructor.
         * @param point Virtual position.
         * @param size Virtual size.
         * @param sprite Block sprite.
         */
        explicit CompositeSpriteBlock(const Components::Point &point, const Components::Size &size,
                                      const std::shared_ptr<Components::ISprite> &sprite);

        /**
         * @brief Method changes block's sprite.
         * @param sprite New sprite.
         */
        void loadNewSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept;

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

        virtual ~CompositeSpriteBlock() = default;

    protected:
        Components::Point _point;
        Components::Size _size;
        Components::Speed _speed;
        std::shared_ptr<Components::ISprite> _sprite;
    };
}

#endif //FLASH_COMPOSITESPRITEBLOCK_H
