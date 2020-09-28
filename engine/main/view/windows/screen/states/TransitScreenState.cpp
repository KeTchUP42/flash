//
// Created by roman on 26.09.2020.
//

#include "TransitScreenState.h"
#include "../../../../objects/generating/level/StartLevelFactory.h"

Screen::TransitScreenState::TransitScreenState(const std::shared_ptr<Unite::Unifier> &unifier) : m_unifier(unifier) {}

void Screen::TransitScreenState::
load(Screen::StateChangeable *context, Managers::DataManager *manager, sf::RenderWindow &target) {
    //todo !!!
    Generating::StartLevelFactory lvl_factory;
    lvl_factory.loadLevel(m_unifier.get(), context, manager, target);
}

void Screen::TransitScreenState::refresh() {
    m_unifier->refresh();
}

void Screen::TransitScreenState::draw(sf::RenderWindow &target) const noexcept {
    m_unifier->draw(target);
}

void Screen::TransitScreenState::update(const sf::Event &event, sf::RenderWindow &sender) {
    m_unifier->update(event, sender);
}

