//
// Created by roman on 20.08.2020.
//

#ifndef FLASH_PRIMARYWINDOW_H
#define FLASH_PRIMARYWINDOW_H

#include "../../base/window/Window.h"
#include "../../../../data/manager/DataManager.h"
#include "../../../../objects/components/sprite/sprite-box/base/ISpriteBox.h"

namespace WindowView {

    class PrimaryWindow : public Window {
    public:
        explicit PrimaryWindow(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style,
                               const sf::ContextSettings &settings, DataManagers::DataManager *dataManager);

        explicit PrimaryWindow(sf::WindowHandle handle, const sf::ContextSettings &settings,
                               DataManagers::DataManager *dataManager);

    private:
        void configure();

    protected:
        void initialization() override;

        void update() override;

    protected:
        std::shared_ptr<Components::ISpriteBox> _background;
        DataManagers::DataManager *_dataManager;
    };
}

#endif //FLASH_PRIMARYWINDOW_H