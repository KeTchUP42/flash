//
// Created by roman on 20.08.2020.
//

#ifndef FLASH_BASEWINDOW_H
#define FLASH_BASEWINDOW_H

#include "../../base/window/Window.h"

namespace Windows {

    class BaseWindow : public Window {
    public:

        explicit BaseWindow(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style = sf::Style::Default,
                            const sf::ContextSettings &settings = sf::ContextSettings());

        explicit BaseWindow(sf::WindowHandle handle, const sf::ContextSettings &settings = sf::ContextSettings());

    private:
        void configure() noexcept;

    protected:
        void initialization() noexcept override;

        void update() noexcept override;
    };
}

#endif //FLASH_BASEWINDOW_H
