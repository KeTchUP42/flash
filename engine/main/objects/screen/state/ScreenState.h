//
// Created by roman on 01.09.2020.
//

#ifndef FLASH_SCREENSTATE_H
#define FLASH_SCREENSTATE_H

#include "../../capabilities/Drawable.h"
#include "../../../data/manager/DataManager.h"
#include "../../../view/windows/base/observer/Observer.h"
#include "../../../view/windows/base/window/Window.h"
#include "../window-abilities/StateChangeable.h"

namespace Screen {

    class StateChangeable;

    /**
     * @brief The base class of the ScreenState class hierarchy.
     * @namespace Screen
     *
     * This class defines base ScreenState interface and fields.
    */
    class ScreenState : public Capabilities::Drawable, public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        /**
         * @brief Constructors may have transit data.
         */
        ScreenState() = default;

        /**
         * @brief Method inits all screen components. ALL overrides MUST call base method.
         * @param window StateChangeable window.
         * @param dataManager Manager for data searching.
         * @param target Draw target.
         */
        virtual void load(StateChangeable *window, DataManagers::DataManager *dataManager, sf::RenderTarget &target);

        virtual ~ScreenState() = default;

    protected:
        /**
         * @brief Do not call "delete" for this ptr.
         */
        StateChangeable *_window;
        /**
         * @brief Do not call "delete" for this ptr.
         */
        DataManagers::DataManager *_dataManager;
    };
}

#endif //FLASH_SCREENSTATE_H
