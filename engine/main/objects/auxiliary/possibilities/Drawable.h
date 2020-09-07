//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_DRAWABLE_H
#define FLASH_DRAWABLE_H

#include <SFML/Graphics.hpp>

namespace Possibilities {

    /**
     * @brief The base class of the Drawable class hierarchy.
     * @namespace Possibilities
     *
     * This class defines base Drawable interface.
    */
    template<class DrawableType = sf::RenderTarget>
    class Drawable {
    public:
        Drawable() = default;

        /**
         * Simple interface method to draw object on T.
         * DrawableType class should have "draw" method.
         *
         * @param target DrawableType reference.
         */
        virtual void draw(DrawableType &target) const noexcept = 0;

        virtual ~Drawable() = default;
    };
}


#endif //FLASH_DRAWABLE_H
