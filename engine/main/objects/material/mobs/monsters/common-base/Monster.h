//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_MONSTER_H
#define FLASH_MONSTER_H

#include "../../../../auxiliary/components/sprite/primitive/ISpriteBox.h"
#include "../common/properties/MonsterProperties.h"
#include "../../../../auxiliary/possibilities/Physical.h"
#include "../../../common/MaterialObject.h"

#include <memory>

namespace Mobs {

    /**
     * @brief The base class of the Monster class hierarchy. Monster - all mobs without players.
     * @namespace Mobs
     *
     * This class defines base Monster interface.
    */
    class Monster : public Material::MaterialObject,
                    public Possibilities::Physical<Mobs::MonsterProperties> {
    public:
        explicit Monster(const Mobs::MonsterProperties &properties, const std::shared_ptr<Components::ISpriteBox> &sprite);

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

        const std::shared_ptr<Components::ISpriteBox> &getSprite() const noexcept;

        const Mobs::MonsterProperties &getProperties() const noexcept override;

    protected:
        Mobs::MonsterProperties m_properties;
        std::shared_ptr<Components::ISpriteBox> m_sprite;
    };
}

#endif //FLASH_MONSTER_H
