//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_COMPOSITESPRITE_H
#define FLASH_COMPOSITESPRITE_H

#include "ICompositeSprite.h"

#include <list>

namespace Components {

    class CompositeSprite : public ICompositeSprite {
    public:
        void draw(sf::RenderTarget &target) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

        /**
         * @brief Method rotates ALL leaf sprites around their coordinates.
         * @param angle Rotate angle.
         */
        void rotate(float angle) noexcept override;

        void rotate(float angle, float x, float y) noexcept override;

        void rotate(float angle, const Point &point) noexcept override;

        bool collision(int x, int y) const noexcept override;

        void update(const sf::Event &event, sf::RenderWindow &sender) noexcept override;

        void addSprite(ISprite *sprite) noexcept override;

        void addSprite(const std::shared_ptr<ISprite> &sprite) noexcept override;

        void removeSprite(const std::shared_ptr<ISprite> &sprite) noexcept override;

    protected:
        std::list<std::shared_ptr<ISprite>> _sprites;
    };
}

#endif //FLASH_COMPOSITESPRITE_H