//
// Created by roman on 10.11.2020.
//

#ifndef FLASH_IMPACTPLAYERTRIGGER_H
#define FLASH_IMPACTPLAYERTRIGGER_H

#include "../ImpactTrigger.h"

namespace Triggers {

    class ImpactPlayerTrigger : public ImpactTrigger<Mobs::Player> {
    public:
        explicit ImpactPlayerTrigger(const Components::Area &area, Handler<Mobs::Player> *handler);

        ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept override;
    };
}

#endif //FLASH_IMPACTPLAYERTRIGGER_H
