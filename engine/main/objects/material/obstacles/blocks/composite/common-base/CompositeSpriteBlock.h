//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_COMPOSITESPRITEBLOCK_H
#define FLASH_COMPOSITESPRITEBLOCK_H

#include "../../../common/Obstacle.h"
#include "../../../../../auxiliary/components/elementary/Area.h"

namespace Obstacles {

    class CompositeSpriteBlock : public Obstacles::Obstacle {
    public:

        explicit CompositeSpriteBlock(const Components::Area &area, const ObstacleProperties &properties,
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

        float getRotation() const noexcept override;

        const Material::MaterialObjectProperties &getProperties() const noexcept override;

        void setPosition(const Components::Point &point) noexcept override;

        void setPosition(float x, float y) noexcept override;

        void setSize(const Components::Size &size) noexcept override;

        void setRotation(float angle) noexcept override;

        virtual ~CompositeSpriteBlock() = default;

    protected:
        Components::Area _area;
        std::shared_ptr<Components::ISprite> _sprite;
    };
}

#endif //FLASH_COMPOSITESPRITEBLOCK_H
