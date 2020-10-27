//
// Created by roman on 20.08.2020.
//

#ifndef FLASH_WINDOWCLOSEOBSERVER_H
#define FLASH_WINDOWCLOSEOBSERVER_H

#include <SFML/Window/Event.hpp>
#include "../window/Window.h"
#include "../observer/Observer.h"

namespace View {
    class WindowCloseObserver : public Observer<sf::Event, View::Window> {
    public:
        void update(const sf::Event &event, View::Window &window) noexcept override;
    };
}

#endif //FLASH_WINDOWCLOSEOBSERVER_H
