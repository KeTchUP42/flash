//
// Created by roman on 01.09.2020.
//

#ifndef FLASH_SCREENSTATE_H
#define FLASH_SCREENSTATE_H

#include "../../../../../objects/auxiliary/possibilities/Drawable.h"
#include "../../context-abilities/StateChangeable.h"
#include "../../../../../data/manager/DataManager.h"
#include "../../../base/observer/Observer.h"
#include "../../../base/window/Window.h"

namespace Screen {

    class StateChangeable;

    /**
     * @brief The base class of the ScreenState class hierarchy.
     * @namespace Screen
     *
     * This class defines base ScreenState interface and fields.
    */
    class ScreenState
            : public Possibilities::Drawable<sf::RenderWindow>,
              public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        /**
         * @brief Constructors may have transit data.
         */
        ScreenState() = default;

        /**
         * @brief Method inits all screen components.
         * @param context StateChangeable context.
         * @param manager Manager for data searching.
         * @param target Render target.
         */
        virtual void load(StateChangeable *context, Managers::DataManager *manager, sf::RenderWindow &target) = 0;

        /**
         * @brief Method uses for components refresh logic.
         */
        virtual void refresh() = 0;

        virtual ~ScreenState() = default;
    };
}

#endif //FLASH_SCREENSTATE_H
