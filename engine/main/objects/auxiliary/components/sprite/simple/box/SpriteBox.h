//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_SPRITEBOX_H
#define FLASH_SPRITEBOX_H

#include "ISpriteBox.h"
#include "../../../simple/Point.h"
#include "../../../simple/Size.h"

#include <memory>

namespace Components {

    class SpriteBox : public ISpriteBox {
    public:
        explicit SpriteBox(const Components::Point &point, const Components::Size &size,
                           const std::shared_ptr<sf::Texture> &texture);

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

        void rotate(float angle) noexcept override;

        void rotate(float angle, float x, float y) noexcept override;

        void rotate(float angle, const Point &point) noexcept override;

        bool collision(int x, int y) const noexcept override;

        void update(const sf::Event &event, sf::RenderWindow &sender) noexcept override;

        void setPosition(const Point &point) noexcept override;

        void setRotation(float angle) noexcept override;

        const Point &getPoint() const noexcept override;

        const Size &getSize() const noexcept override;

    protected:
        Components::Point _point;
        Components::Size _size;
        std::shared_ptr<sf::Texture> _texture;
        std::shared_ptr<sf::Sprite> _sprite;
    };
}

#endif //FLASH_SPRITEBOX_H
