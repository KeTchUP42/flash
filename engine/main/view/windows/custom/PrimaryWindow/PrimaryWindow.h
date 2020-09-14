//
// Created by roman on 20.08.2020.
//

#ifndef FLASH_PRIMARYWINDOW_H
#define FLASH_PRIMARYWINDOW_H

#include "../../base/window/Window.h"
#include "../../../../data/manager/DataManager.h"
#include "../../screen/states/common-base/ScreenState.h"
#include "../../screen/context-abilities/StateChangeable.h"

namespace WindowView {

    class PrimaryWindow : public Window, public Screen::StateChangeable {
    public:
        explicit PrimaryWindow(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style,
                               const sf::ContextSettings &settings, Screen::ScreenState *screenState,
                               Managers::DataManager *manager);

        explicit PrimaryWindow(sf::WindowHandle handle, const sf::ContextSettings &settings,
                               Screen::ScreenState *screenState, Managers::DataManager *manager);

    private:
        void configure();

    protected:
        void initialization() override;

        void update() override;

    public:
        void setScreenState(Screen::ScreenState *state) noexcept override;

    private:
        /**
         * @brief Current window screen state.
         */
        std::shared_ptr<Screen::ScreenState> _screen;
        Managers::DataManager *_manager;
    };
}

#endif //FLASH_PRIMARYWINDOW_H