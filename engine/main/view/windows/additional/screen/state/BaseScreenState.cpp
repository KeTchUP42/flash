//
// Created by roman on 01.09.2020.
//

#include "BaseScreenState.h"
#include "../../../../../objects/auxiliary/components/sprite/factory/background/PrimaryBackGroundFactory.h"

void Screen::BaseScreenState::load(StateChangeable *context, Managers::DataManager *dataManager, sf::RenderTarget &target) {
    ScreenState::load(context, dataManager, target);

    Components::PrimaryBackGroundFactory factory;
    _background = factory.createSpriteBox(_dataManager, Components::Size(target.getSize().x, target.getSize().y));
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
