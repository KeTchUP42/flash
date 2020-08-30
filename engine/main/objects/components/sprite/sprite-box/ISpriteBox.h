//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_ISPRITEBOX_H
#define FLASH_ISPRITEBOX_H

#include "../../../../view/windows/base/observer/Observer.h"
#include "../../../capabilities/Drawable.h"
#include "../../../capabilities/Movable.h"
#include "../../../capabilities/CollisionProne.h"
#include "../../simple/Point.h"
#include "../../simple/Size.h"

#include <SFML/Graphics.hpp>

namespace Components {

    /**
     * @brief The base class of the ISpriteBox class hierarchy.
     * @namespace Components
     *
     * This class is a base leaf component interface.
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

        /**
         * @brief Method returns SpriteBox Point.
         * @return const Point&
         */
        virtual const Point &getPoint() const noexcept = 0;

        /**
         * @brief Method returns SpriteBox Size.
         * @return const Size&
         */
        virtual const Size &getSize() const noexcept = 0;

        virtual ~ISpriteBox() = default;
    };
}

#endif //FLASH_ISPRITEBOX_H
