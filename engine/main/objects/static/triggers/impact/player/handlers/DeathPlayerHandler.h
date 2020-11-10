//
// Created by roman on 10.11.2020.
//

#ifndef FLASH_DEATHPLAYERHANDLER_H
#define FLASH_DEATHPLAYERHANDLER_H

#include "../../../common/handler/Handler.h"
#include "../../../../../material/mobs/players/common/base/Player.h"

namespace Triggers {

    class DeathPlayerHandler : public Handler<Mobs::Player> {
    public:
        void handle(Mobs::Player &object) const noexcept override;
    };
}

#endif //FLASH_DEATHPLAYERHANDLER_H
