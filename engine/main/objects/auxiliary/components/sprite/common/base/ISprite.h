//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_ISPRITE_H
#define FLASH_ISPRITE_H

#include "../../../../../../view/windows/base/observer/Observer.h"
#include "../../../../possibilities/Drawable.h"
#include "../../../../possibilities/Movable.h"
#include "../../../../possibilities/Rotatable.h"
#include "../../../../possibilities/CollisionProne.h"
#include "../../../elementary/Point.h"
#include "../../../elementary/Size.h"

#include <SFML/Graphics.hpp>

namespace Components {

    /**
     * @brief The base class of the ISprite class hierarchy.
     * @namespace Components
     *
     * This class is a base leaf component interface.
    */
    class ISprite
            : public Possibilities::Movable,
              public Possibilities::Rotatable,
              public Possibilities::CollisionProne,
              public Possibilities::Drawable<sf::RenderTarget>,
              public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        ISprite() = default;

        /**
         * @brief Method deletes operator= method.
         * @return ISprite&
         */
        ISprite &operator=(const ISprite &) = delete;

        virtual ~ISprite() = default;
    };
}

#endif //FLASH_ISPRITE_H
