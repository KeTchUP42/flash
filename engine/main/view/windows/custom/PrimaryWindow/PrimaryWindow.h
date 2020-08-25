//
// Created by roman on 20.08.2020.
//

#ifndef FLASH_PRIMARYWINDOW_H
#define FLASH_PRIMARYWINDOW_H

#include "../../base/window/Window.h"
#include "../../../../data/manager/DataManager.h"

namespace WindowView {

    class PrimaryWindow : public Window {
    public:
        explicit PrimaryWindow(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style,
                               const sf::ContextSettings &settings, DataManagers::DataManager *dataManager);

        explicit PrimaryWindow(sf::WindowHandle handle, const sf::ContextSettings &settings,
                               DataManagers::DataManager *dataManager);

    private:
        void configure() noexcept;

    protected:
        void initialization() noexcept override;

        void update() override;

    private:
        std::shared_ptr<DataManagers::DataManager> _dataManager; //todo: Think to make _dataManager general ptr.
    };
}

#endif //FLASH_PRIMARYWINDOW_H