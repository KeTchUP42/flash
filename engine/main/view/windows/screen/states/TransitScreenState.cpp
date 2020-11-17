//
// Created by roman on 26.09.2020.
//

#include "TransitScreenState.h"
#include "../../../../objects/creation/scene/SceneLoader.h"

View::TransitScreenState::TransitScreenState(const std::string &filename, Unite::Unifier *unifier)
        : View::ScreenState(filename), m_unifier(unifier) {}

void View::TransitScreenState::
load(View::StateChangeable *context, Managers::DataManager *manager, View::Window &window) {
    Creation::SceneLoader loader(context, manager);
    loader.loadScene(m_scene_file, *m_unifier, window);
}

void View::TransitScreenState::refresh() {
    m_unifier->refresh();
}

void View::TransitScreenState::draw(sf::RenderWindow &target) const noexcept {
    m_unifier->draw(target);
}

void View::TransitScreenState::update(const sf::Event &event, View::Window &sender) {
    m_unifier->update(event, sender);
}

