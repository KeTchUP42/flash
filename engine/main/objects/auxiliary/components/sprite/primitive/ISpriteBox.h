//
// Created by roman on 31.08.2020.
//

#ifndef FLASH_ISPRITEBOX_H
#define FLASH_ISPRITEBOX_H

#include "../common-base/ISprite.h"
#include "../../../possibilities/RectangleGetters.h"
#include "../../../possibilities/RectangleSetters.h"

#include <memory>

namespace Components {

    class ISpriteBox : public Possibilities::RectangleGetters,
                       public Possibilities::RectangleSetters,
                       public ISprite {
    public:
        ISpriteBox() = default;

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
    };
}

#endif //FLASH_ISPRITEBOX_H
