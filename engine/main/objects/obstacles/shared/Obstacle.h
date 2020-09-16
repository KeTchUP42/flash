//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_OBSTACLE_H
#define FLASH_OBSTACLE_H

#include "../../auxiliary/possibilities/Drawable.h"
#include "../../auxiliary/possibilities/Movable.h"
#include "../../auxiliary/possibilities/CollisionProne.h"
#include "../../auxiliary/possibilities/Rotatable.h"
#include "../../auxiliary/possibilities/SelfActionable.h"
#include "../../auxiliary/possibilities/SelfMovable.h"
#include "../../auxiliary/possibilities/RectangleGetters.h"
#include "../../auxiliary/possibilities/RectangleSetters.h"
#include "../../../view/windows/base/observer/Observer.h"
#include "../../auxiliary/components/elementary/Size.h"
#include "../../unifier/common-base/Unifier.h"

#include <SFML/Graphics.hpp>

namespace Unite {
    class Unifier;
}

namespace Obstacles {

    /**
     * @brief The base class of the Obstacle class hierarchy. It contains all usefull interfaces.
     * @namespace Obstacles
     *
     * This class defines base Obstacle interface.
    */
    class Obstacle :
            public Possibilities::SelfActionable<Unite::Unifier>,
            public Possibilities::SelfMovable<Unite::Unifier>,
            public Possibilities::Movable,
            public Possibilities::CollisionProne,
            public Possibilities::Rotatable,
            public Possibilities::RectangleGetters,
            public Possibilities::RectangleSetters,
            public Possibilities::Drawable<sf::RenderTarget>,
            public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        Obstacle() = default;

        /**
         * @brief Method deletes "operator=".
         * @return Obstacle
         */
        Obstacle &operator=(const Obstacle &) = delete;

        virtual ~Obstacle() = default;
    };
}

#endif //FLASH_OBSTACLE_H
