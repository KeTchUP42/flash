//
// Created by roman on 11.11.2020.
//

#ifndef FLASH_IMPACTMOBSZONE_H
#define FLASH_IMPACTMOBSZONE_H

#include "../ImpactZone.h"

namespace Triggers {

    class ImpactMobsZone : public ImpactZone<Mobs::Mob> {
    public:
        explicit ImpactMobsZone(const Components::Area &area, Handler<Mobs::Mob> *handler);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;
    };
}

#endif //FLASH_IMPACTMOBSZONE_H
