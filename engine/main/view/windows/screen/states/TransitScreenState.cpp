//
// Created by roman on 26.09.2020.
//

#include "TransitScreenState.h"
#include "../../../../objects/generation/scene/SceneGenerator.h"

Screen::TransitScreenState::TransitScreenState(const std::string &filename, Unite::Unifier *unifier)
        : Screen::ScreenState(filename), m_unifier(unifier) {}

void Screen::TransitScreenState::
load(Screen::StateChangeable *context, Managers::DataManager *manager, sf::RenderWindow &target) {
    Generate::SceneGenerator generator(context, manager);
    generator.loadScene(m_scene_file, *m_unifier.get(), target);
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

