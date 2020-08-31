//
// Created by roman on 20.08.2020.
//

#include "PrimaryWindow.h"
#include "../../base/observers/WindowCloseObserver.h"
#include "../../../../objects/components/sprite/factory/background/PrimaryBackGroundFactory.h"

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
    this->addObserver(new WindowCloseObserver());

    using namespace Components;
    PrimaryBackGroundFactory factory;
    _background = factory.createSpriteBox(_dataManager, Size(_window.getSize().x, _window.getSize().y));
    //..
}

void WindowView::PrimaryWindow::update() {
    _window.clear(sf::Color(50, 50, 50));
    _background->draw(_window);

    _window.display();
}