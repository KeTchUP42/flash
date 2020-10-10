//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_SPRITEBOX_H
#define FLASH_SPRITEBOX_H

#include "ISpriteBox.h"
#include "../../elementary/area/Area.h"

namespace Components {

    class SpriteBox : public ISpriteBox {
    public:
        explicit SpriteBox(const Components::Area &area, const std::shared_ptr<sf::Texture> &texture);

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

        void rotate(float angle) noexcept override;

        void rotate(float angle, float x, float y) noexcept override;

        void rotate(float angle, const Components::Point &point) noexcept override;

        void setPosition(const Components::Point &point) noexcept override;

        void setPosition(float x, float y) noexcept override;

        void setSize(const Components::Size &size) noexcept override;

        void setRotation(float angle) noexcept override;

        float getRotation() const noexcept override;

        const std::shared_ptr<sf::Sprite> &getSprite() const noexcept override;

        const sf::Texture *getTexture() const noexcept override;

        void setTexture(const std::shared_ptr<sf::Texture> &texture) noexcept override;

        const sf::IntRect &getTextureRect() const noexcept override;

        sf::Color getColor() const noexcept override;

        void setColor(const sf::Color &color) noexcept override;

        const Components::Point &getPosition() const noexcept override;

        const Components::Size &getSize() const noexcept override;

    protected:
        Components::Area m_area;
        std::shared_ptr<sf::Texture> m_texture;
        std::shared_ptr<sf::Sprite> m_sprite;
    };
}

#endif //FLASH_SPRITEBOX_H
