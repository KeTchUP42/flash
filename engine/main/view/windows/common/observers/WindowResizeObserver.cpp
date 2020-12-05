//
// Created by roman on 25.08.2020.
//

#include "WindowResizeObserver.h"

void View::WindowResizeObserver::update(const sf::Event &event, View::Window &window) noexcept {
    if (event.type == sf::Event::Resized) {
        //..
        window.getWindow().display();
    }
}
