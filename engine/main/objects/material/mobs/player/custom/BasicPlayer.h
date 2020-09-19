//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_BASICPLAYER_H
#define FLASH_BASICPLAYER_H

#include "../common-base/BasePlayer.h"
#include "../../../shared/collision/CollisionStrategy.h"
#include "../../../shared/collision/ObstacleCollision.h"
#include "../../../shared/collision/Collision.h"

namespace Mobs {

    class BasicPlayer : public BasePlayer {
    public:
        explicit BasicPlayer(const std::shared_ptr<Components::ISpriteBox> &sprite,
                             const std::shared_ptr<Material::Collision> &collision);

        explicit BasicPlayer(const std::shared_ptr<Components::ISpriteBox> &sprite,
                             Material::Collision *collision);

        void selfAction(Unite::Unifier *unifier) override;

        void selfMove(Unite::Unifier *unifier) override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;

        void loadKeyMap(const std::string &filename, Managers::DataManager *manager) override;
    };
}

#endif //FLASH_BASICPLAYER_H
