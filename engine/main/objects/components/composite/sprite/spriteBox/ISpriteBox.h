//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_ISPRITEBOX_H
#define FLASH_ISPRITEBOX_H

#include "../../../../../view/windows/base/observer/Observer.h"

#include "../../../../capabilities/Drawable.h"
#include "../../../../capabilities/Movable.h"
#include "../../../../capabilities/CollisionProne.h"


#include <SFML/Graphics.hpp>

namespace Components {

    /**
     * @brief The base leaf of composite sprite.
     * @namespace Components
     *
     * This class is a base leaf component.
    */
    class ISpriteBox
            : public Capabilities::Drawable,
              public Capabilities::Movable,
              public Capabilities::CollisionProne,
              public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        ISpriteBox() = default;

        /**
         * @brief Method deletes operator= method.
         * @return ISpriteBox&
         */
        ISpriteBox &operator=(const ISpriteBox &) = delete;

        virtual ~ISpriteBox() = default;
    };
}

#endif //FLASH_ISPRITEBOX_H
