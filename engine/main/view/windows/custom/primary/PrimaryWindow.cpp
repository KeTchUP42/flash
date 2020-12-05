//
// Created by roman on 20.08.2020.
//

#include "PrimaryWindow.h"
#include "../../common/observers/WindowCloseObserver.h"

View::PrimaryWindow::PrimaryWindow(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style,
                                   const sf::ContextSettings &settings, View::ScreenState *screenState, Managers::DataManager *manager)
        : Window(mode, title, style, settings), m_state(screenState), m_manager(manager) {}

View::PrimaryWindow::PrimaryWindow(sf::WindowHandle handle, const sf::ContextSettings &settings,
                                   View::ScreenState *screenState, Managers::DataManager *manager)
        : Window(handle, settings), m_state(screenState), m_manager(manager) {}

void View::PrimaryWindow::configure() {
    this->initialization();
}

void View::PrimaryWindow::initialization() {
    this->addObserver(new WindowCloseObserver());
    //Place, where you can add more std observers.
    m_state->load(this, m_manager, *this);
    this->addObserver(m_state);
}

void View::PrimaryWindow::update() {
    m_state->refresh();
    m_state->draw(*m_window);
}

void View::PrimaryWindow::setScreenState(View::ScreenState *state) {
    this->removeObserver(m_state);
    m_state.reset(state); //Method calls "delete" for an old one ptr.
    m_state->load(this, m_manager, *this);
    this->addObserver(m_state);
}
