//
// Created by roman on 23.09.2020.
//

#ifndef FLASH_AREA_H
#define FLASH_AREA_H

#include "../../../possibilities/RectangleGetters.h"
#include "../../../possibilities/RectangleSetters.h"
#include "../../../possibilities/CollisionProne.h"
#include "../../../possibilities/Movable.h"
#include "../../../possibilities/Rotatable.h"
#include "../point/Point.h"
#include "../Size.h"

namespace Components {

    /**
     * @brief Base component.
     * @namespace Components
     *
     * This struct is the base component.
    */
    struct Area : public Possibilities::RectangleGetters,
                  public Possibilities::RectangleSetters,
                  public Possibilities::Rotatable,
                  public Possibilities::Movable {

        /**
         * @brief Inits all fields by zero.
         */
        Area();

        explicit Area(const Point &point, const Size &size, float angle);

        void move(float offsetX, float offsetY) noexcept override;

        void rotate(float angle) noexcept override;

        void rotate(float angle, float x, float y) noexcept override;

        void rotate(float angle, const Point &point) noexcept override;

        void setPosition(const Point &point) noexcept override;

        void setPosition(float x, float y) noexcept override;

        void setSize(const Size &size) noexcept override;

        void setRotation(float angle) noexcept override;

        const Point &getPosition() const noexcept override;

        const Size &getSize() const noexcept override;

        float getRotation() const noexcept override;

        float m_angle;
        Components::Point m_point;
        Components::Size m_size;
    };
}

#endif //FLASH_AREA_H
