//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_JUMPINGPLAYER_H
#define FLASH_JUMPINGPLAYER_H

#include "../../common/base/AnalyzingPlayer.h"
#include "properties/JumpingPlayerProperties.h"

namespace Mobs {

    class JumpingPlayer : public AnalyzingPlayer {
    public:
        explicit JumpingPlayer(
                const MobProperties &properties,
                const Components::Area &area,
                const std::shared_ptr<Components::ISpriteBox> &sprite,
                const std::shared_ptr<Material::Algorithms> &algorithms,
                const JumpingPlayerProperties &jumping
        );

        void selfAction(Unite::Unifier *unifier) override;

        void handleEvent(const sf::Event &event, Unite::Unifier *unifier) noexcept override;

    protected:
        Mobs::JumpingPlayerProperties m_jumping;
    };
}

#endif //FLASH_JUMPINGPLAYER_H
