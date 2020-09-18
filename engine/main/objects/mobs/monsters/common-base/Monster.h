//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_MONSTER_H
#define FLASH_MONSTER_H

#include "../../../auxiliary/components/sprite/common/box/ISpriteBox.h"
#include "../../shared/Mob.h"

#include <memory>

namespace Mobs {

    /**
     * @brief The base class of the Monster class hierarchy.
     * @namespace Mobs
     *
     * This class defines base Monster interface.
    */
    class Monster : public Mob {
    public:
        explicit Monster(const std::shared_ptr<Components::ISpriteBox> &sprite);

        /**
         * @brief Method changes monsters's sprite texture.
         * @param texture New texture.
         */
        void loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept;

        bool collision(float x, float y) const noexcept override;

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

        const Components::Point &getPosition() const noexcept override;

        const Components::Size &getSize() const noexcept override;

        float getRotation() const noexcept override;

        void rotate(float angle) noexcept override;

        void rotate(float angle, float x, float y) noexcept override;

        void rotate(float angle, const Components::Point &point) noexcept override;

        void addSpeed(float offsetX, float offsetY) noexcept override;

        void setMoveSpeed(const Components::Speed &speed) noexcept override;

        const Components::Speed &getMoveSpeed() const noexcept override;

    protected:
        Components::Speed _speed;
        std::shared_ptr<Components::ISpriteBox> _sprite;
    };
}

#endif //FLASH_MONSTER_H
