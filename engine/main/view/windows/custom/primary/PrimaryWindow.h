//
// Created by roman on 20.08.2020.
//

#ifndef FLASH_PRIMARYWINDOW_H
#define FLASH_PRIMARYWINDOW_H

#include "../../common/window/Window.h"
#include "../../../../data/manager/DataManager.h"
#include "../../screen/states/common-base/ScreenState.h"
#include "../../screen/context-abilities/StateChangeable.h"

namespace View {

    class PrimaryWindow : public Window, public View::StateChangeable {
    public:
        explicit PrimaryWindow(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style,
                               const sf::ContextSettings &settings, View::ScreenState *screenState, Managers::DataManager *manager);

        explicit PrimaryWindow(sf::WindowHandle handle, const sf::ContextSettings &settings,
                               View::ScreenState *screenState, Managers::DataManager *manager);

    public:
        void configure();

        void setScreenState(View::ScreenState *state) override;

    protected:
        void initialization() override;

        void update() override;

    private:
        /**
         * @brief Current window screen state.
         */
        std::shared_ptr<View::ScreenState> m_state;

        /**
         * @brief Do not call "delete" for this ptr.
        */
        Managers::DataManager *m_manager;
    };
}

#endif //FLASH_PRIMARYWINDOW_H