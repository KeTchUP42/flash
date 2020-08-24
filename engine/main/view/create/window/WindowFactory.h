//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_WINDOWFACTORY_H
#define FLASH_WINDOWFACTORY_H

#include <memory>

#include "../../windows/base/window/Window.h"

namespace ViewCreate {

    /**
     * @brief The base class of the WindowFactory factory class hierarchy.
     * @namespace ViewCreate
     *
     * This class defines base WindowFactory interface.
    */
    class WindowFactory {
    public:
        WindowFactory() = default;

        /**
         * @brief Base factory method. You can add any additional logic to it.
         * @param mode sf::VideoMode
         * @param title const sf::String&
         * @param style sf::Uint32
         * @param settings const sf::ContextSettings&
         * @return new Window std::shared_pt<Windows::Window>
         */
        virtual std::shared_ptr<Windows::Window>
        createWindow(sf::VideoMode mode, const sf::String &title, sf::Uint32 style,
                     const sf::ContextSettings &settings) const noexcept = 0;

        /**
         * @brief Base factory method. You can add any additional logic to it.
         * @param handle sf::WindowHandle
         * @param settings const sf::ContextSettings&
         * @return new Window std::shared_pt<Windows::Window>
         */
        virtual std::shared_ptr<Windows::Window>
        createWindow(sf::WindowHandle handle, const sf::ContextSettings &settings) const noexcept = 0;

        virtual ~WindowFactory() = default;
    };
}
#endif //FLASH_WINDOWFACTORY_H
