//
// Created by roman on 11.11.2020.
//

#ifndef FLASH_DEATHMOBSHANDLER_H
#define FLASH_DEATHMOBSHANDLER_H

#include "../../../common/handler/Handler.h"
#include "../../../../../material/mobs/common/base/Mob.h"

namespace Triggers {

    class DeathMobsHandler : public Handler<Mobs::Mob> {
    public:
        void handle(Mobs::Mob &object) const noexcept override;
    };
}

#endif //FLASH_DEATHMOBSHANDLER_H
