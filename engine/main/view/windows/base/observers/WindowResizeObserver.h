//
// Created by roman on 25.08.2020.
//

#ifndef FLASH_WINDOWRESIZEOBSERVER_H
#define FLASH_WINDOWRESIZEOBSERVER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "../observer/Observer.h"

namespace WindowView {
    class WindowResizeObserver : public Observer<sf::RenderWindow, sf::Event> {
    public:
        void update(const sf::Event &event, sf::RenderWindow &window) noexcept override;
    };
}

#endif //FLASH_WINDOWRESIZEOBSERVER_H
