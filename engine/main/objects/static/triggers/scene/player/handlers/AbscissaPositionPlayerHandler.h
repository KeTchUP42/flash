//
// Created by roman on 04.10.2020.
//

#ifndef FLASH_ABSCISSAPOSITIONPLAYERHANDLER_H
#define FLASH_ABSCISSAPOSITIONPLAYERHANDLER_H

#include "../../handler/Handler.h"
#include "../../../../../material/mobs/player/common/base/Player.h"

namespace Triggers {

    class AbscissaPositionPlayerHandler : public Handler<Mobs::Player> {
    public:
        AbscissaPositionPlayerHandler(float abscissa);

        void handle(Mobs::Player &object) const noexcept override;

    protected:
        float m_abscissa;
    };
}

#endif //FLASH_ABSCISSAPOSITIONPLAYERHANDLER_H
