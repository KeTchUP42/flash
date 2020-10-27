//
// Created by roman on 20.08.2020.
//

#include "WindowCloseObserver.h"

void View::WindowCloseObserver::update(const sf::Event &event, View::Window &window) noexcept {
    if (event.type == sf::Event::Closed) {
        window.getWindow().close();
    }
}
