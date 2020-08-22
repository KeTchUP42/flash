//
// Created by roman on 20.08.2020.
//

#ifndef FLASH_PRIMARYWINDOW_H
#define FLASH_PRIMARYWINDOW_H

#include "../../base/window/Window.h"

namespace Windows {

    class PrimaryWindow : public Window {
    public:

        explicit PrimaryWindow(const sf::VideoMode &mode, const sf::String &title,
                               sf::Uint32 style = sf::Style::Default,
                               const sf::ContextSettings &settings = sf::ContextSettings());

        explicit PrimaryWindow(sf::WindowHandle handle,
                               const sf::ContextSettings &settings = sf::ContextSettings());

    private:
        void configure() noexcept;

    protected:
        void initialization() noexcept override;

        void update() noexcept override;
    };
}

#endif //FLASH_PRIMARYWINDOW_H