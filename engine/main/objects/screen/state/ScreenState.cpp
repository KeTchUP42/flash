//
// Created by roman on 01.09.2020.
//

#include "ScreenState.h"

void
Screen::ScreenState::load(StateChangeable *window, DataManagers::DataManager *dataManager, sf::RenderTarget &target) {
    _window = window;
    _dataManager = dataManager;
}
