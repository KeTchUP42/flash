//
// Created by roman on 01.11.2020.
//

#ifndef FLASH_BLOCK_H
#define FLASH_BLOCK_H

#include "../../common/Obstacle.h"
#include "../../../../auxiliary/possibilities/rectangle/Rectangle.h"

namespace Obstacles {

    class Block : public Obstacle, public Possibilities::Rectangle {
    public:
        /**
         * @brief Default block constructor.
         * @param material_properties Material properties.
         * @param properties Mob properties object.
         * @param area Mob physical area.
         */
        explicit Block(const Material::MaterialProperties &material_properties, const ObstacleProperties &properties, const Components::Area &area);

        void updateCoordinates() noexcept override;

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

        virtual ~Block() = default;

    private:
        Components::Area m_AreaDump = m_area;

    protected:
        Components::Area m_area;
    };
}

#endif //FLASH_BLOCK_H
