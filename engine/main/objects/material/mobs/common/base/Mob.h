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
     * @brief This class is the base class for all kinds of mobs. It contains all needed basic realization.
     * @namespace Mobs
     *
     * This class defines base Mob interface and realization.
    */
    class Mob : public Material::MaterialObject, public Possibilities::Rectangle,
                public Possibilities::Peculiar<MobProperties> {
    public:
        /**
         * @brief Default mob constructor.
         * @param material_properties Material properties.
         * @param properties Mob properties object.
         * @param area Mob physical area.
         * @param sprite Mob sprite.
         */
        Mob(const Material::MaterialProperties &material_properties,
            const Mobs::MobProperties &properties,
            const Components::Area &area,
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

        const std::shared_ptr<Components::ISpriteBox> &getSprite() const noexcept;

        const Components::Area &getPhysicalArea() const noexcept;

        const MobProperties &getProperties() const noexcept override;

        /**
         * @brief Method sets new max health points value.
         * @param healthPoints New max health points value.
         */
        void setMaxHealthPoints(float healthPoints) noexcept;

        /**
         * @brief Method checks is mob dead.
         * @return Is dead?
         */
        bool isDead() const noexcept;

        /**
         * @brief Method hits the mob with damage.
         * @param damage Damage value.
         */
        void dealDamage(float damage) noexcept;

        /**
         * @brief Method kills the mob.
         */
        void kill() noexcept;

        /**
         * @brief Method sets new health points value.
         * @param healthPoints New health points value.
         */
        void setHealthPoints(float healthPoints) noexcept;

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
