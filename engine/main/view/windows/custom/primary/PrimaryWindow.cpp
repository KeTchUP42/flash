//
// Created by roman on 20.08.2020.
//

#include "PrimaryWindow.h"
#include "../../base/observers/WindowCloseObserver.h"

WindowView::PrimaryWindow::PrimaryWindow(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style,
                                         const sf::ContextSettings &settings, Screen::ScreenState *screenState,
                                         Managers::DataManager *manager)
        : Window(mode, title, style, settings), m_state(screenState), m_manager(manager) {}

WindowView::PrimaryWindow::PrimaryWindow(sf::WindowHandle handle, const sf::ContextSettings &settings,
                                         Screen::ScreenState *screenState, Managers::DataManager *manager)
        : Window(handle, settings), m_state(screenState), m_manager(manager) {}

void WindowView::PrimaryWindow::configure() {
    this->initialization();
}

void WindowView::PrimaryWindow::initialization() {
    this->addObserver(new WindowCloseObserver());
    //Place, where you can add more std observers.
    m_state->load(this, m_manager, m_window);
    this->addObserver(m_state);
}

void WindowView::PrimaryWindow::update() {
    m_state->refresh();
    m_state->draw(m_window);
    m_window.display();
}

void WindowView::PrimaryWindow::setScreenState(Screen::ScreenState *state) noexcept {
    this->removeObserver(m_state);
    m_state.reset(state); //Method calls "delete" for an old one ptr.
    m_state->load(this, m_manager, m_window);
    this->addObserver(m_state);
}
