//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_ISPRITEBOX_H
#define FLASH_ISPRITEBOX_H

#include "../../../../../../view/windows/base/observer/Observer.h"
#include "../../../../possibilities/Drawable.h"
#include "../../../../possibilities/Movable.h"
#include "../../../../possibilities/Rotatable.h"
#include "../../../../possibilities/CollisionProne.h"
#include "../../../simple/Point.h"
#include "../../../simple/Size.h"

#include <SFML/Graphics.hpp>

namespace Components {

    /**
     * @brief The base class of the ISpriteBox class hierarchy.
     * @namespace Components
     *
     * This class is a base leaf component interface.
    */
    class ISpriteBox
            : public Possibilities::Drawable,
              public Possibilities::Movable,
              public Possibilities::Rotatable,
              public Possibilities::CollisionProne,
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
