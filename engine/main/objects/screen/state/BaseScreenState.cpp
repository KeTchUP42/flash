//
// Created by roman on 01.09.2020.
//

#include "BaseScreenState.h"
#include "../../components/sprite/factory/background/PrimaryBackGroundFactory.h"

void Screen::BaseScreenState::load(StateChangeable *window, DataManagers::DataManager *dataManager,
                                   sf::RenderTarget &target) {
    ScreenState::load(window, dataManager, target);

    using namespace Components;
    PrimaryBackGroundFactory factory;
    _background = factory.createSpriteBox(_dataManager, Size(target.getSize().x, target.getSize().y));
}

void Screen::BaseScreenState::refresh() {
    // Some components logic.
    // Example: _background->move(1, 0);
}

void Screen::BaseScreenState::draw(sf::RenderTarget &target) const noexcept {
    target.clear(sf::Color(50, 50, 50));
    _background->draw(target);
    //..
}

void Screen::BaseScreenState::update(const sf::Event &event, sf::RenderWindow &sender) noexcept {
    // todo: If I call _window->setScreenState(new BaseScreenState()); here,
    // todo: I will have error signal in Window->notify() because "observer == nullptr". Think how to fix.
}
