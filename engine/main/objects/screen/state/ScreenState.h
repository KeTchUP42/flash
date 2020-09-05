//
// Created by roman on 01.09.2020.
//

#ifndef FLASH_SCREENSTATE_H
#define FLASH_SCREENSTATE_H

#include "../../possibilities/Drawable.h"
#include "../../possibilities/Refreshable.h"
#include "../../../data/manager/DataManager.h"
#include "../../../view/windows/base/observer/Observer.h"
#include "../../../view/windows/base/window/Window.h"
#include "../context-abilities/StateChangeable.h"

namespace Screen {

    class StateChangeable;

    /**
     * @brief The base class of the ScreenState class hierarchy.
     * @namespace Screen
     *
     * This class defines base ScreenState interface and fields.
    */
    class ScreenState
            : public Possibilities::Drawable,
              public Possibilities::Refreshable,
              public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        /**
         * @brief Constructors may have transit data.
         */
        ScreenState() = default;

        /**
         * @brief Method inits all screen components. ALL overrides MUST call base method.
         * @param context StateChangeable context.
         * @param dataManager Manager for data searching.
         * @param target Render target.
         */
        virtual void load(StateChangeable *context, Managers::DataManager *dataManager, sf::RenderTarget &target);

        virtual ~ScreenState() = default;

    protected:
        /**
         * @brief Do not call "delete" for this ptr.
         */
        StateChangeable *_context;
        /**
         * @brief Do not call "delete" for this ptr.
         */
        Managers::DataManager *_dataManager;
    };
}

#endif //FLASH_SCREENSTATE_H
