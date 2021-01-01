//
// Created by roman on 04.10.2020.
//

#ifndef FLASH_EXPLICITPOSITIONPLAYERHANDLER_H
#define FLASH_EXPLICITPOSITIONPLAYERHANDLER_H

#include "../../../common/handler/Handler.h"
#include "../../../../../material/mobs/players/common/base/Player.h"

namespace Triggers {

    class ExplicitPositionPlayerHandler : public Handler<Mobs::Player> {
    public:
        explicit ExplicitPositionPlayerHandler(const Components::Point &target);

        void handle(Mobs::Player &object) const noexcept override;

    protected:
        Components::Point m_target;
    };
}

#endif //FLASH_EXPLICITPOSITIONPLAYERHANDLER_H
