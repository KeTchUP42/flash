//
// Created by roman on 11.11.2020.
//

#ifndef FLASH_IMPACTMOBSTRIGGER_H
#define FLASH_IMPACTMOBSTRIGGER_H

#include "../ImpactTrigger.h"

namespace Triggers {

    class ImpactMobsTrigger : public ImpactTrigger<Mobs::Mob> {
    public:
        explicit ImpactMobsTrigger(const Components::Area &area, Handler<Mobs::Mob> *handler);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;
    };
}

#endif //FLASH_IMPACTMOBSTRIGGER_H
