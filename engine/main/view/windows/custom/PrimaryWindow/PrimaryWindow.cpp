//
// Created by roman on 20.08.2020.
//

#include "PrimaryWindow.h"
#include "../../base/observers/WindowCloseObserver.h"

WindowView::PrimaryWindow::PrimaryWindow(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style,
                                         const sf::ContextSettings &settings, Screen::ScreenState *screenState,
                                         DataManagers::DataManager *dataManager)
        : _dataManager(dataManager), _screen(screenState), Window(mode, title, style, settings) {
    this->configure();
}

WindowView::PrimaryWindow::PrimaryWindow(sf::WindowHandle handle, const sf::ContextSettings &settings,
                                         Screen::ScreenState *screenState,
                                         DataManagers::DataManager *dataManager)
        : _dataManager(dataManager), _screen(screenState), Window(handle, settings) {
    this->configure();
}

void WindowView::PrimaryWindow::configure() {
    this->initialization();
}

void WindowView::PrimaryWindow::initialization() {
    this->addObserver(new WindowCloseObserver());
    // Place, where you can add more std observers.
    _screen->load(this, _dataManager, _window);
    this->addObserver(_screen);
}

void WindowView::PrimaryWindow::update() {
    _screen->draw(_window);
    _window.display();
}

void WindowView::PrimaryWindow::setScreenState(Screen::ScreenState *state) noexcept {
    if (state == nullptr) return;
    this->removeObserver(_screen);
    _screen.reset(state); //Method calls "delete" for an old one ptr.
    _screen->load(this, _dataManager, _window);
    this->addObserver(_screen);
}
