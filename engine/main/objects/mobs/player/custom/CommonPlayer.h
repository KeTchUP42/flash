//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_COMMONPLAYER_H
#define FLASH_COMMONPLAYER_H

#include "../base/Player.h"

namespace Mobs {

    class CommonPlayer : public Player {
    public:
        explicit CommonPlayer(const std::shared_ptr<Components::ISpriteBox> &sprite);

        void selfAction(Unite::Unifier *unifier) override;

        void selfMove(Unite::Unifier *unifier) override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;

        ~CommonPlayer() override = default;
    };
}

#endif //FLASH_COMMONPLAYER_H
