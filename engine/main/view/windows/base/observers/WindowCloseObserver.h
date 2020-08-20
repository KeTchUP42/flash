//
// Created by roman on 20.08.2020.
//

#ifndef FLASH_WINDOWCLOSEOBSERVER_H
#define FLASH_WINDOWCLOSEOBSERVER_H

#include "../observer/Observer.h"

namespace Windows {
    class WindowCloseObserver : public Observer<sf::Window, sf::Event> {
    public:
        void update(const sf::Event &event, sf::Window &window) noexcept override;
    };
}

#endif //FLASH_WINDOWCLOSEOBSERVER_H
