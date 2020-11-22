//
// Created by roman on 01.09.2020.
//

#include "InitialScreenState.h"
#include "../../../../objects/unifier/SceneUnifier.h"
#include "../../../../objects/creation/scene/SceneLoader.h"

View::InitialScreenState::InitialScreenState(const std::string &filename) : ScreenState(filename) {}

void View::InitialScreenState::
load(StateChangeable *context, Managers::DataManager *manager, View::Window &window) {
    m_unifier = std::make_shared<Unite::SceneUnifier>();
    Creation::SceneLoader loader(context, manager);
    loader.loadScene(m_scene_file, *m_unifier, window);
}

void View::InitialScreenState::refresh() {
    m_unifier->refresh();
}

void View::InitialScreenState::draw(sf::RenderWindow &target) const noexcept {
    m_unifier->draw(target);
}

void View::InitialScreenState::update(const sf::Event &event, View::Window &sender) {
    m_unifier->update(event, sender);
}
