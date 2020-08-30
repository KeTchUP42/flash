//
// Created by roman on 20.08.2020.
//

#ifndef FLASH_WINDOWCLOSEOBSERVER_H
#define FLASH_WINDOWCLOSEOBSERVER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "../observer/Observer.h"

namespace WindowView {
    class WindowCloseObserver : public Observer<sf::RenderWindow, sf::Event> {
    public:
        void update(const sf::Event &event, sf::RenderWindow &window) noexcept override;
    };
}

#endif //FLASH_WINDOWCLOSEOBSERVER_H
