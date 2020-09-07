//
// Created by roman on 01.09.2020.
//

#include "BaseScreenState.h"
#include "../../../../../objects/auxiliary/components/sprite/factory/background/PrimaryBackGroundFactory.h"
#include "../../../../../objects/auxiliary/components/sprite/factory/sprite/StoneWallSpriteFactory.h"

void Screen::BaseScreenState::load(StateChangeable *context, Managers::DataManager *dataManager, sf::RenderWindow &target) {
    ScreenState::load(context, dataManager, target);

    using namespace Components;
    using namespace Components::Factory;

    PrimaryBackGroundFactory factory;
    _background = factory.createSpriteBox(Size(target.getSize().x, target.getSize().y), _dataManager);

    StoneWallSpriteFactory wall_factory;
    _block = wall_factory.createSprite(Point(300, 300), Size(100, 100), _dataManager);
    //_block->rotate(360);
    //_block->collision(300, 300);
}

void Screen::BaseScreenState::refresh() {
    _block->rotate(1);
    // Some components logic.
    // Example: _background->move(1, 0);
}

void Screen::BaseScreenState::draw(sf::RenderWindow &target) const noexcept {
    target.clear(sf::Color(50, 50, 50));
    _background->draw(target);
    _block->draw(target);
    //..
}

void Screen::BaseScreenState::update(const sf::Event &event, sf::RenderWindow &sender) noexcept {
    // todo: If I call _window->setScreenState(new BaseScreenState()); here,
    // todo: I will have error signal in Window->notify() because "observer == nullptr". Think how to fix.
}
