//
// Created by roman on 20.08.2020.
//

#include "PrimaryWindow.h"

WindowView::PrimaryWindow::PrimaryWindow(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style,
                                         const sf::ContextSettings &settings, DataManagers::DataManager *dataManager)
        : _dataManager(dataManager), Window(mode, title, style, settings) {

    this->configure();
}

WindowView::PrimaryWindow::PrimaryWindow(sf::WindowHandle handle, const sf::ContextSettings &settings,
                                         DataManagers::DataManager *dataManager)
        : _dataManager(dataManager), Window(handle, settings) {

    this->configure();
}

void WindowView::PrimaryWindow::configure() {
    this->initialization();
}

void WindowView::PrimaryWindow::initialization() {
    //..
}

void WindowView::PrimaryWindow::update() {
    //_window.display();
}