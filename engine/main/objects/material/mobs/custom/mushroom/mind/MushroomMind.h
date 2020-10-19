//
// Created by roman on 07.10.2020.
//

#ifndef FLASH_MUSHROOMMIND_H
#define FLASH_MUSHROOMMIND_H

#include "../../../common/mind/Mind.h"

namespace Mobs {
    class Mushroom;
}

namespace Mobs {

    class MushroomMind : public Mind<Mushroom> {
    public:
        MushroomMind(Mushroom *holder);

        void analyze(Unite::Unifier *unifier) noexcept override;
    };
}

#include "../Mushroom.h"

#endif //FLASH_MUSHROOMMIND_H
