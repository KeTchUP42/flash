//
// Created by roman on 20.08.2020.
//

#include "WindowCloseObserver.h"

void WindowView::WindowCloseObserver::update(const sf::Event &event, sf::Window &window) noexcept {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
}
