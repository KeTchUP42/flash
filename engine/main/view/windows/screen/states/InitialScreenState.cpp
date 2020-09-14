//
// Created by roman on 01.09.2020.
//

#include "InitialScreenState.h"
#include "../../../../objects/generating/components/background/PrimaryBackGroundFactory.h"
#include "../../../../objects/generating/level/StartLevelFactory.h"

void Screen::InitialScreenState::load(StateChangeable *context, Managers::DataManager *manager, sf::RenderWindow &target) {
    ScreenState::load(context, manager, target);

    using namespace Components;
    using namespace ComponentsGenerating;

    PrimaryBackGroundFactory factory;
    _background = factory.createSpriteBox(target.getSize(), _manager);

    LevelGenerating::StartLevelFactory lvl_factory;
    _unifier = lvl_factory.loadLevel(target.getSize(), _context, _manager);
}

void Screen::InitialScreenState::refresh() {
    _unifier->refresh();
}

void Screen::InitialScreenState::draw(sf::RenderWindow &target) const noexcept {
    _background->draw(target);
    _unifier->draw(target);
}

void Screen::InitialScreenState::update(const sf::Event &event, sf::RenderWindow &sender) {
    _unifier->update(event, sender);
}
