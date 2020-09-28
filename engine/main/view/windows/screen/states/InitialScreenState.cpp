//
// Created by roman on 01.09.2020.
//

#include "InitialScreenState.h"
#include "../../../../objects/generating/level/StartLevelFactory.h"

void Screen::InitialScreenState::load(StateChangeable *context, Managers::DataManager *manager, sf::RenderWindow &target) {
    Generating::StartLevelFactory lvl_factory;
    m_unifier = lvl_factory.loadLevel(context, manager, target);
}

void Screen::InitialScreenState::refresh() {
    m_unifier->refresh();
}

void Screen::InitialScreenState::draw(sf::RenderWindow &target) const noexcept {
    m_unifier->draw(target);
}

void Screen::InitialScreenState::update(const sf::Event &event, sf::RenderWindow &sender) {
    m_unifier->update(event, sender);
}
