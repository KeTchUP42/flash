//
// Created by roman on 20.08.2020.
//

#include "PrimaryWindow.h"

Windows::PrimaryWindow::PrimaryWindow(const sf::VideoMode &mode, const sf::String &title, sf::Uint32 style,
                                      const sf::ContextSettings &settings, DataManagers::DataManager *dataManager)
        : _dataManager(dataManager), Window(mode, title, style, settings) {

    this->configure();
}

Windows::PrimaryWindow::PrimaryWindow(sf::WindowHandle handle, const sf::ContextSettings &settings,
                                      DataManagers::DataManager *dataManager)
        : _dataManager(dataManager), Window(handle, settings) {

    this->configure();
}

void Windows::PrimaryWindow::setDataManager(DataManagers::DataManager *dataManager) {
    _dataManager = std::shared_ptr<DataManagers::DataManager>(dataManager);
}

void Windows::PrimaryWindow::configure() noexcept {
    this->initialization();
}

void Windows::PrimaryWindow::initialization() noexcept {
    //..
}

void Windows::PrimaryWindow::update() noexcept {
    //_window.display();
}