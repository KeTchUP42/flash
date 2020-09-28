//
// Created by roman on 20.08.2020.
//

#include "PrimaryWindow.h"
#include "../../base/observers/WindowCloseObserver.h"

WindowView::PrimaryWindow::PrimaryWindow(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style,
                                         const sf::ContextSettings &settings, Screen::ScreenState *screenState,
                                         Managers::DataManager *manager)
        : Window(mode, title, style, settings), _state(screenState), _manager(manager) {
    this->configure();
}

WindowView::PrimaryWindow::PrimaryWindow(sf::WindowHandle handle, const sf::ContextSettings &settings,
                                         Screen::ScreenState *screenState, Managers::DataManager *manager)
        : Window(handle, settings), _state(screenState), _manager(manager) {
    this->configure();
}

void WindowView::PrimaryWindow::configure() {
    this->initialization();
}

void WindowView::PrimaryWindow::initialization() {
    this->addObserver(new WindowCloseObserver());
    //Place, where you can add more std observers.
    _state->load(this, _manager, _window);
    this->addObserver(_state);
}

void WindowView::PrimaryWindow::update() {
    _state->refresh();
    _state->draw(_window);
    _window.display();
}

void WindowView::PrimaryWindow::setScreenState(Screen::ScreenState *state) noexcept {
    if (state == nullptr) return;
    this->removeObserver(_state);
    _state.reset(state); //Method calls "delete" for an old one ptr.
    _state->load(this, _manager, _window);
    this->addObserver(_state);
}
