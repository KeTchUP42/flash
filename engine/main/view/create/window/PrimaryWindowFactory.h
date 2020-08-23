//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_PRIMARYWINDOWFACTORY_H
#define FLASH_PRIMARYWINDOWFACTORY_H

#include "WindowFactory.h"

namespace ViewCreate {

    class PrimaryWindowFactory : public WindowFactory {
    public:
        std::shared_ptr<Windows::Window>
        createWindow(sf::VideoMode mode, const sf::String &title, sf::Uint32 style,
                     const sf::ContextSettings &settings) const noexcept override;

        std::shared_ptr<Windows::Window>
        createWindow(sf::WindowHandle handle, const sf::ContextSettings &settings) const noexcept override;
    };
}
#endif //FLASH_PRIMARYWINDOWFACTORY_H
