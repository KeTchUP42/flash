//
// Created by roman on 08.09.2020.
//

#ifndef FLASH_MOB_H
#define FLASH_MOB_H

#include "../../auxiliary/possibilities/Drawable.h"
#include "../../auxiliary/possibilities/Movable.h"
#include "../../auxiliary/possibilities/CollisionProne.h"
#include "../../auxiliary/possibilities/Rotatable.h"
#include "../../auxiliary/possibilities/SelfActionable.h"
#include "../../auxiliary/possibilities/SelfMovable.h"
#include "../../../view/windows/base/observer/Observer.h"
#include "../../auxiliary/components/elementary/Size.h"
#include "../../auxiliary/possibilities/RectangleGetters.h"
#include "../../unifier/base/Unifier.h"

#include <SFML/Graphics.hpp>

namespace Unite {
    class Unifier;
}

namespace Mobs {

    /**
     * @brief The base class of the Mob class hierarchy. It contains all usefull interfaces.
     * @namespace Mobs
     *
     * This class defines base Mob interface.
    */
    class Mob :
            public Possibilities::SelfActionable<Unite::Unifier>,
            public Possibilities::SelfMovable<Unite::Unifier>,
            public Possibilities::Movable,
            public Possibilities::CollisionProne,
            public Possibilities::Rotatable,
            public Possibilities::RectangleGetters,
            public Possibilities::Drawable<sf::RenderTarget>,
            public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        Mob() = default;

        /**
         * @brief Method deletes "operator=".
         * @return Mob
         */
        Mob &operator=(const Mob &) = delete;

        virtual ~Mob() = default;
    };
}

#endif //FLASH_MOB_H
