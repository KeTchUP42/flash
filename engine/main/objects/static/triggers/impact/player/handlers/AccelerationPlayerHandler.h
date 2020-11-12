//
// Created by roman on 12.11.2020.
//

#ifndef FLASH_ACCELERATIONPLAYERHANDLER_H
#define FLASH_ACCELERATIONPLAYERHANDLER_H

#include "../../../common/handler/Handler.h"
#include "../../../../../material/mobs/players/common/base/Player.h"

namespace Triggers {

    class AccelerationPlayerHandler : public Handler<Mobs::Player> {
    public:
        explicit AccelerationPlayerHandler(float accelerationX, float accelerationY);

        void handle(Mobs::Player &object) const noexcept override;

    private:
        const float X_ACCELERATION;
        const float Y_ACCELERATION;
    };
}

#endif //FLASH_ACCELERATIONPLAYERHANDLER_H
