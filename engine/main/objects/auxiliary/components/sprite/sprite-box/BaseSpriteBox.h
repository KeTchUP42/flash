//
// Created by roman on 31.08.2020.
//

#ifndef FLASH_BASESPRITEBOX_H
#define FLASH_BASESPRITEBOX_H

#include "base/ISpriteBox.h"

namespace Components {

    class BaseSpriteBox : public ISpriteBox {
    public:
        BaseSpriteBox() = default;

        /**
         * @brief Method sets new position point.
         * @param point New Point.
         */
        virtual void setPosition(const Components::Point &point) noexcept = 0;

        /**
         * @brief Method sets new rotation value.
         * @param angle Rotation value.
         */
        virtual void setRotation(float angle) noexcept = 0;

        /**
         * @brief Method returns SpriteBox Point.
         * @return Sprite point.
         */
        virtual const Point &getPoint() const noexcept = 0;

        /**
         * @brief Method returns SpriteBox Size.
         * @return Sprite size.
         */
        virtual const Size &getSize() const noexcept = 0;
    };
}

#endif //FLASH_BASESPRITEBOX_H
