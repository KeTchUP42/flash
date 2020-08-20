//
// Created by roman on 20.08.2020.
//

#include "BaseWindow.h"
#include "../../observers/WindowCloseObserver.h"

Windows::BaseWindow::BaseWindow(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style,
                                const sf::ContextSettings &settings) : Window(mode, title, style, settings) {
    this->configure();
}

Windows::BaseWindow::BaseWindow(sf::WindowHandle handle, const sf::ContextSettings &settings) : Window(handle, settings) {
    this->configure();
}

void Windows::BaseWindow::configure() noexcept {
    this->initialization();
}

void Windows::BaseWindow::initialization() noexcept {
    this->addObserver(new WindowCloseObserver());
}

void Windows::BaseWindow::update() noexcept {
    //_window.display();
}


