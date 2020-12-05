//
// Created by roman on 25.08.2020.
//

#ifndef FLASH_WINDOWRESIZEOBSERVER_H
#define FLASH_WINDOWRESIZEOBSERVER_H

#include <SFML/Window/Event.hpp>
#include "../window/Window.h"
#include "../observer/Observer.h"

namespace View {
    class WindowResizeObserver : public Observer<sf::Event, View::Window> {
    public:
        void update(const sf::Event &event, View::Window &window) noexcept override;
    };
}

#endif //FLASH_WINDOWRESIZEOBSERVER_H
