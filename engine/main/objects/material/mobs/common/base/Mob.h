//
// Created by roman on 17.09.2020.
//

#ifndef FLASH_MOB_H
#define FLASH_MOB_H

#include "../../../../auxiliary/components/sprite/primitive/ISpriteBox.h"
#include "../../../../auxiliary/components/elementary/area/Area.h"
#include "../../../../auxiliary/possibilities/Peculiar.h"
#include "../../../common/MaterialObject.h"
#include "../properties/MobProperties.h"

namespace Mobs {

    /**
     * @brief The class represents the base class of all Mobs.
     * @namespace Mobs
     *
     * This class defines base Mob interface and realization.
    */
    class Mob : public Material::MaterialObject,
                public Possibilities::Rectangle,
                public Possibilities::Peculiar<MobProperties> {
    public:
        /**
         * @brief Main mob constructor.
         * @param properties Mob properties object.
         * @param area Mob physical area.
         * @param sprite Mob sprite.
         */
        explicit Mob(const MobProperties &properties, const Components::Area &area,
                     const std::shared_ptr<Components::ISpriteBox> &sprite);

        /**
         * @brief Method changes mob's sprite texture.
         * @param texture New texture.
         */
        void loadNewTexture(const std::shared_ptr<sf::Texture> &texture) noexcept;

        void updateCoordinates() noexcept override;

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

        void setXSpeed(float xSpeed) noexcept override;

        void setYSpeed(float ySpeed) noexcept override;

        void setSpeed(const Components::Speed &speed) noexcept override;

        const Components::Speed &getSpeed() const noexcept override;

        const std::shared_ptr<Components::ISpriteBox> &getSprite() const noexcept;

        const Components::Area &getPhysicalArea() const noexcept;

        const MobProperties &getProperties() const noexcept override;

        /**
         * @brief Method sets new health points value.
         * @param health Points New health points value.
         */
        void setHealthPoints(float healthPoints) noexcept;

        /**
         * @brief Method checks is mob dead.
         * @return Is dead?
         */
        bool isDead() const noexcept;

        /**
         * @brief Method hits the mob with damage.
         * @param damage Damage value.
         */
        void prejudice(float damage) noexcept;

        /**
         * @brief Method kills the mob.
         */
        void kill() noexcept;

    private:
        Components::Area m_AreaDump = m_area;

    protected:
        Components::Area m_area;
        MobProperties m_properties;
        std::shared_ptr<Components::ISpriteBox> m_sprite;
    };
}

#include "../../../../unifier/common/Unifier.h"

#endif //FLASH_MOB_H
