//
// Created by roman on 04.10.2020.
//

#ifndef FLASH_ORDINATEPOSITIONPLAYERHANDLER_H
#define FLASH_ORDINATEPOSITIONPLAYERHANDLER_H

#include "../../handler/Handler.h"
#include "../../../../../material/mobs/players/common/base/Player.h"

namespace Triggers {

    class OrdinatePositionPlayerHandler : public Handler<Mobs::Player> {
    public:
        OrdinatePositionPlayerHandler(float ordinate);

        void handle(Mobs::Player &object) const noexcept override;

    protected:
        float m_ordinate;
    };
}

#endif //FLASH_ORDINATEPOSITIONPLAYERHANDLER_H
