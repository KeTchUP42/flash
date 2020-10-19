//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_MOB_H
#define FLASH_MOB_H

#include "../../../../auxiliary/components/elementary/area/Area.h"
#include "../../../../auxiliary/components/sprite/primitive/ISpriteBox.h"
#include "../../../../auxiliary/possibilities/Physical.h"
#include "../../../common/MaterialObject.h"
#include "../properties/MobProperties.h"

namespace Mobs {

    /**
     * @brief The base class of the Mob class hierarchy.
     * @namespace Mobs
     *
     * This class defines base Mob interface and realization.
    */
    class Mob : public Material::MaterialObject,
                public Possibilities::Physical<MobProperties> {
    public:
        explicit Mob(const MobProperties &properties, const Components::Area &area,
                     const std::shared_ptr<Components::ISpriteBox> &sprite);

        /**
         * @brief Method changes mob's sprite texture.
         * @param texture New texture.
         */
        void loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept;

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

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

        const std::shared_ptr<Components::ISpriteBox> &getSprite() const noexcept;

        const MobProperties &getProperties() const noexcept override;

    protected:
        Components::Area m_area;
        MobProperties m_properties;
        std::shared_ptr<Components::ISpriteBox> m_sprite;
    };
}

#include "../../../../unifier/common/Unifier.h"

#endif //FLASH_MOB_H
