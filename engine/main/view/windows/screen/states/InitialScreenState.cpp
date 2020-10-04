//
// Created by roman on 01.09.2020.
//

#include "InitialScreenState.h"
#include "../../../../objects/unifier/GeneralUnifier.h"
#include "../../../../objects/generation/scene/SceneGenerator.h"

Screen::InitialScreenState::InitialScreenState(const std::string &filename) : ScreenState(filename) {}

void Screen::InitialScreenState::load(StateChangeable *context, Managers::DataManager *manager, sf::RenderWindow &target) {
    m_unifier = std::make_shared<Unite::GeneralUnifier>();
    Generating::SceneGenerator generator(context, manager);
    generator.loadScene(m_SceneFileName, *m_unifier.get(), target);
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
