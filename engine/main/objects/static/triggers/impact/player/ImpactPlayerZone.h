//
// Created by roman on 10.11.2020.
//

#ifndef FLASH_IMPACTPLAYERZONE_H
#define FLASH_IMPACTPLAYERZONE_H

#include "../ImpactZone.h"

namespace Triggers {

    class ImpactPlayerZone : public ImpactZone<Mobs::Player> {
    public:
        explicit ImpactPlayerZone(const Components::Area &area, Handler<Mobs::Player> *handler);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;
    };
}

#endif //FLASH_IMPACTPLAYERZONE_H
