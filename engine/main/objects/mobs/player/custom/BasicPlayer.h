//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_BASICPLAYER_H
#define FLASH_BASICPLAYER_H

#include "../base/Player.h"
#include "../../shared/collision/CollisionStrategy.h"

namespace Mobs {

    class BasicPlayer : public Player {
    public:
        explicit BasicPlayer(const std::shared_ptr<Components::ISpriteBox> &sprite,
                             const std::shared_ptr<CollisionStrategy<std::shared_ptr<Obstacles::Obstacle>>> &collision);

        explicit BasicPlayer(const std::shared_ptr<Components::ISpriteBox> &sprite,
                             CollisionStrategy<std::shared_ptr<Obstacles::Obstacle>> *collision);

        void selfAction(Unite::Unifier *unifier) override;

        void selfMove(Unite::Unifier *unifier) override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;

        void loadKeyMap(const std::string &filename, Managers::DataManager *manager) override;

        ~BasicPlayer() override = default;

    protected:
        std::shared_ptr<CollisionStrategy<std::shared_ptr<Obstacles::Obstacle>>> _collision;
    };
}

#endif //FLASH_BASICPLAYER_H
