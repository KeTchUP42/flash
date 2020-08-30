//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_SPRITEBOX_H
#define FLASH_SPRITEBOX_H

#include "ISpriteBox.h"
#include "../../../../components/simple/Point.h"
#include "../../../../components/simple/Size.h"

#include <memory>

namespace Components {

    class SpriteBox : public ISpriteBox {
    public:
        explicit SpriteBox(Components::Point point, Components::Size size, std::shared_ptr<sf::Texture> texture);

        void draw(sf::RenderTarget &target) const noexcept override;

        void move(int x, int y) noexcept override;

        bool collision(int x, int y) const noexcept override;

        void update(const sf::Event &event, sf::RenderWindow &sender) noexcept override;

    protected:
        Components::Point _point;
        Components::Size _size;
        std::shared_ptr<sf::Texture> _texture;
        std::shared_ptr<sf::Sprite> _sprite;
    };
}

#endif //FLASH_SPRITEBOX_H
