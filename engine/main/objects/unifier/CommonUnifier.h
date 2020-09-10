//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_COMMONUNIFIER_H
#define FLASH_COMMONUNIFIER_H

#include "base/Unifier.h"

namespace Unite {

    class CommonUnifier : public Unifier {
    public:
        explicit CommonUnifier(Screen::StateChangeable *context);

        void draw(sf::RenderWindow &target) const noexcept override;

        void refresh() override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;
    };
}

#endif //FLASH_COMMONUNIFIER_H
