//
// Created by roman on 01.09.2020.
//

#include "BaseScreenState.h"
#include "../../../../objects/generating/components/background/PrimaryBackGroundFactory.h"
#include "../../../../objects/generating/components/sprites/StoneWallSpriteFactory.h"

void Screen::BaseScreenState::load(StateChangeable *context, Managers::DataManager *manager, sf::RenderWindow &target) {
    ScreenState::load(context, manager, target);

    using namespace Components;
    using namespace ComponentsGenerating;

    PrimaryBackGroundFactory factory;
    _background = factory.createSpriteBox(target.getSize(), _manager);

    StoneWallSpriteFactory wall_factory;
    _block = wall_factory.createSprite(Point(540, 360), Size(50, 50), _dataManager);
}

void Screen::BaseScreenState::refresh() {
    _block->rotate(1, 640, 385);
}

void Screen::BaseScreenState::draw(sf::RenderWindow &target) const noexcept {
    _background->draw(target);
    _block->draw(target);
}

void Screen::BaseScreenState::update(const sf::Event &event, sf::RenderWindow &sender) noexcept {
    // todo: If I call _window->setScreenState(new BaseScreenState()); here,
    // todo: I will have error signal in Window->notify() because "observer == nullptr". Think how to fix.
}
