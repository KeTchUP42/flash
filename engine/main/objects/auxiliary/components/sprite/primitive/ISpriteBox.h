//
// Created by roman on 31.08.2020.
//

#ifndef FLASH_ISPRITEBOX_H
#define FLASH_ISPRITEBOX_H

#include "../common-base/ISprite.h"
#include "../../../possibilities/rectangle/RectangleGetters.h"
#include "../../../possibilities/rectangle/RectangleSetters.h"
#include "../../elementary/area/Area.h"

#include <memory>

namespace Components {

    class ISpriteBox : public ISprite, public Possibilities::RectangleGetters, public Possibilities::RectangleSetters {
    public:
        /**
         * @brief Base custom sprite constructor.
         * @param texture Sprite texture.
         * @param sprite Base sprite.
         */
        explicit ISpriteBox(const std::shared_ptr<sf::Texture> &texture, sf::Sprite *sprite);

        /**
         * @brief Base custom sprite constructor.
         * @param texture Sprite texture.
         * @param sprite Base sprite.
         */
        explicit ISpriteBox(const std::shared_ptr<sf::Texture> &texture, const std::shared_ptr<sf::Sprite> &sprite);

        /**
         * @brief Method returns origin sprite.
         * @return Sprite.
         */
        const std::shared_ptr<sf::Sprite> &getSprite() const noexcept;

        /**
         * @brief Method returns sprite texture.
         * @return Texture pointer.
         */
        const sf::Texture *getTexture() const noexcept;

        /**
         * @brief Method sets new sprite texture.
         */
        void setTexture(const std::shared_ptr<sf::Texture> &texture) noexcept;

        /**
         * @brief Method returns texture rect.
         * @return Texture rect.
         */
        const sf::IntRect &getTextureRect() const noexcept;

        /**
         * @brief Method returns sprite box area.
         * @return Sprite box area.
         */
        virtual const Components::Area &getArea() const noexcept = 0;

        /**
         * @brief Method return sprite color.
         * @return Color.
         */
        sf::Color getColor() const noexcept;

        /**
         * @brief Method sets sprite color.
         * @param color Color.
         */
        void setColor(const sf::Color &color) noexcept;

    protected:
        std::shared_ptr<sf::Texture> m_texture;
        std::shared_ptr<sf::Sprite> m_sprite;
    };
}

#endif //FLASH_ISPRITEBOX_H
