//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_BASICPLAYER_H
#define FLASH_BASICPLAYER_H

#include "../../common/base/BasePlayer.h"
#include "../../../../common/collision/Collision.h"
#include "properties/BasicPlayerProperties.h"

namespace Mobs {

    class BasicPlayer : public BasePlayer {
    public:
        explicit BasicPlayer(const MobProperties &properties, const Components::Area &area, const std::shared_ptr<Components::ISpriteBox> &sprite,
                             const std::shared_ptr<Material::Algorithms> &algorithms, const BasicPlayerProperties &params);

        void selfAction(Unite::Unifier *unifier) override;

        void selfMove(Unite::Unifier *unifier) override;

        void update(const sf::Event &event, sf::RenderWindow &sender) override;

        void loadKeyMap(const std::string &filename, Managers::DataManager *manager) override;

    protected:
        Mobs::BasicPlayerProperties m_basic;
    };
}

#endif //FLASH_BASICPLAYER_H
