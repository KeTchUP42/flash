//
// Created by roman on 01.09.2020.
//

#include "ScreenState.h"

void Screen::ScreenState::load(StateChangeable *context, Managers::DataManager *manager, sf::RenderWindow &target) {
    _context = context;
    _manager = manager;
}
