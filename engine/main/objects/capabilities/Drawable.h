//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_DRAWABLE_H
#define FLASH_DRAWABLE_H

#include <SFML/Graphics.hpp>

namespace Capabilities {

    /**
     * @brief The base class of the Drawable class hierarchy.
     * @namespace Capabilities
     *
     * This class defines base Drawable interface.
    */
    class Drawable {
    public:
        Drawable() = default;

        /**
         * @brief Simple interface method to draw object on sf::RenderTarget.
         * @param target Render-target reference.
         */
        virtual void draw(sf::RenderTarget &target) const noexcept = 0;

        virtual ~Drawable() = default;
    };
}


#endif //FLASH_DRAWABLE_H
