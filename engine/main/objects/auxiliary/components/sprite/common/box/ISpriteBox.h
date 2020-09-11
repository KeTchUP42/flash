//
// Created by roman on 31.08.2020.
//

#ifndef FLASH_ISPRITEBOX_H
#define FLASH_ISPRITEBOX_H

#include "../base/ISprite.h"

#include <memory>

namespace Components {

    class ISpriteBox : public ISprite {
    public:
        ISpriteBox() = default;

        /**
         * @brief Method sets new position point.
         * @param point New Point.
         */
        virtual void setPosition(const Components::Point &point) noexcept = 0;

        /**
         * @brief Method sets new position point.
         * @param x coordinate.
         * @param y coordinate.
         */
        virtual void setPosition(float x, float y) noexcept = 0;

        /**
         * @brief Method sets new rotation value.
         * @param angle Rotation angle.
         */
        virtual void setRotation(float angle) noexcept = 0;

        /**
         * @brief Method returns origin sprite.
         * @return Sprite.
         */
        virtual const std::shared_ptr<sf::Sprite> &getSprite() const noexcept = 0;

        /**
         * @brief Method returns sprite texture.
         * @return Texture ptr.
         */
        virtual const sf::Texture *const getTexture() const noexcept = 0;

        /**
         * @brief Method sets new sprite texture.
         */
        virtual void setTexture(const std::shared_ptr<sf::Texture> &texture) noexcept = 0;

        /**
         * @brief Method returns texture rect.
         * @return Texture rect.
         */
        virtual const sf::IntRect &getTextureRect() const noexcept = 0;

        /**
         * @brief Method return sprite color.
         * @return Color.
         */
        virtual sf::Color getColor() const noexcept = 0;

        /**
         * @brief Method sets sprite color.
         * @param color Color.
         */
        virtual void setColor(const sf::Color &color) noexcept = 0;

        /**
         * @brief Method returns SpriteBox position.
         * @return Sprite point.
         */
        virtual const Point &getPosition() const noexcept = 0;

        /**
         * @brief Method returns SpriteBox size.
         * @return Sprite size.
         */
        virtual const Size &getSize() const noexcept = 0;
    };
}

#endif //FLASH_ISPRITEBOX_H
