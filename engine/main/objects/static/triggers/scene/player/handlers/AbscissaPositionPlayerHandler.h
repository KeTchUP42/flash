//
// Created by roman on 04.10.2020.
//

#ifndef FLASH_ABSCISSAPOSITIONPLAYERHANDLER_H
#define FLASH_ABSCISSAPOSITIONPLAYERHANDLER_H

#include "../../../common/handler/Handler.h"
#include "../../../../../material/mobs/players/common/base/Player.h"

namespace Triggers {

    class AbscissaPositionPlayerHandler : public Handler<Mobs::Player> {
    public:
        explicit AbscissaPositionPlayerHandler(float abscissa);

        void handle(Mobs::Player &object) const noexcept override;

    protected:
        float m_abscissa;
    };
}

#endif //FLASH_ABSCISSAPOSITIONPLAYERHANDLER_H
