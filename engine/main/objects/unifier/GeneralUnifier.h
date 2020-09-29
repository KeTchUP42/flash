//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_GENERALUNIFIER_H
#define FLASH_GENERALUNIFIER_H

#include "common/Unifier.h"

namespace Unite {

    class GeneralUnifier : public Unifier {
    public:
        void draw(sf::RenderWindow &target) const noexcept override;

        void refresh() override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;
    };
}

#endif //FLASH_GENERALUNIFIER_H
