//
// Created by roman on 12.11.2020.
//

#ifndef FLASH_ACCELERATIONMOBSHANDLER_H
#define FLASH_ACCELERATIONMOBSHANDLER_H

#include "../../../common/handler/Handler.h"
#include "../../../../../material/mobs/common/base/Mob.h"

namespace Triggers {

    class AccelerationMobsHandler : public Handler<Mobs::Mob> {
    public:
        explicit AccelerationMobsHandler(float accelerationX, float accelerationY);

        void handle(Mobs::Mob &object) const noexcept override;

    private:
        const float X_ACCELERATION;
        const float Y_ACCELERATION;
    };
}

#endif //FLASH_ACCELERATIONMOBSHANDLER_H
