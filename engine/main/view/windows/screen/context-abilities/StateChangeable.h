//
// Created by roman on 01.09.2020.
//

#ifndef FLASH_STATECHANGEABLE_H
#define FLASH_STATECHANGEABLE_H

#include "../states/base/ScreenState.h"

namespace Screen {

    class ScreenState;

    /**
     * @brief The base class of the StateChangeable class hierarchy.
     * @namespace Screen
     *
     * This class defines base StateChangeable interface.
    */
    class StateChangeable {
    public:
        StateChangeable() = default;

        /**
         * @brief ScreenState setter. Uses for dynamic content changing.
         * @param state New ScreenState.
         */
        virtual void setScreenState(Screen::ScreenState *state) noexcept = 0;

        virtual ~StateChangeable() = default;
    };
}

#endif //FLASH_STATECHANGEABLE_H
