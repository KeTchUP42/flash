//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_COMPOSITESPRITEBOX_H
#define FLASH_COMPOSITESPRITEBOX_H

#include "ICompositeSpriteBox.h"

#include <list>

namespace Components {

    class CompositeSpriteBox : public ICompositeSpriteBox {
    public:
        void draw(sf::RenderTarget &target) const noexcept override;

        void move(int xlength, int ylength) noexcept override;

        void rotate(float angle) override;

        bool collision(int x, int y) const noexcept override;

        void update(const sf::Event &event, sf::RenderWindow &sender) noexcept override;

        void addSpriteBox(ISpriteBox *spriteBox) noexcept override;

        void addSpriteBox(const std::shared_ptr<ISpriteBox> &spriteBox) noexcept override;

        void removeSpriteBox(const std::shared_ptr<ISpriteBox> &spriteBox) noexcept override;

    protected:
        std::list<std::shared_ptr<ISpriteBox>> _spriteBoxes;
    };
}

#endif //FLASH_COMPOSITESPRITEBOX_H
