//
// Created by roman on 08.09.2020.
//

#ifndef FLASH_MOB_H
#define FLASH_MOB_H

#include "../../auxiliary/possibilities/Drawable.h"
#include "../../auxiliary/possibilities/Movable.h"
#include "../../auxiliary/possibilities/CollisionProne.h"
#include "../../auxiliary/possibilities/Rotatable.h"
#include "../../../view/windows/base/observer/Observer.h"

#include <SFML/Graphics.hpp>

namespace Mobs {

    /**
     * @brief The base class of the Mob class hierarchy. It contains all usefull interfaces.
     * @namespace Mobs
     *
     * This class defines base Mob interface.
    */
    class Mob : public Possibilities::Movable,
                public Possibilities::CollisionProne,
                public Possibilities::Rotatable,
                public Possibilities::Drawable<sf::RenderTarget>,
                public WindowView::Observer<sf::RenderWindow, sf::Event> {

    };
}

#endif //FLASH_MOB_H
