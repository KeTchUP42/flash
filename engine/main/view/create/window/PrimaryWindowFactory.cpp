//
// Created by roman on 23.08.2020.
//

#include "PrimaryWindowFactory.h"
#include "../../windows/custom/PrimaryWindow/PrimaryWindow.h"
#include "../../windows/base/observers/WindowCloseObserver.h"

std::shared_ptr<Windows::Window>
ViewCreate::PrimaryWindowFactory::createWindow(sf::VideoMode mode, const sf::String &title, sf::Uint32 style,
                                               const sf::ContextSettings &settings) const noexcept {
    using namespace Windows;
    Window *window = new PrimaryWindow(mode, title, style, settings);
    window->addObserver(new WindowCloseObserver());
    //..
    return std::shared_ptr<Windows::Window>(window);
}

std::shared_ptr<Windows::Window>
ViewCreate::PrimaryWindowFactory::createWindow(sf::WindowHandle handle, const sf::ContextSettings &settings) const noexcept {
    using namespace Windows;
    Window *window = new PrimaryWindow(handle, settings);
    window->addObserver(new WindowCloseObserver());
    //..
    return std::shared_ptr<Windows::Window>(window);
}
