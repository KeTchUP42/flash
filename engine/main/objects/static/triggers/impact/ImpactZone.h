//
// Created by roman on 10.11.2020.
//

#ifndef FLASH_IMPACTZONE_H
#define FLASH_IMPACTZONE_H

#include "../common/AreaTrigger.h"
#include "../common/handler/Handler.h"

namespace Triggers {

    template<class Type>
    class ImpactZone : public AreaTrigger {
    public:
        explicit ImpactZone(const Components::Area &area, Handler<Type> *handler) : AreaTrigger(area), m_handler(handler) {}

    protected:
        std::shared_ptr<Handler<Type>> m_handler;
    };
}

#endif //FLASH_IMPACTZONE_H
