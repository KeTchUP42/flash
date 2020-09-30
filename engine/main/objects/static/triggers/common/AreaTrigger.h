//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_AREATRIGGER_H
#define FLASH_AREATRIGGER_H

#include "Trigger.h"
#include "../../../auxiliary/components/elementary/area/Area.h"

namespace Triggers {

    /**
     * @brief The base class of the AreaTrigger class hierarchy. Base interface class for scene triggers.
     * @namespace Triggers
     *
     * This class defines base AreaTrigger interface.
    */
    class AreaTrigger : public Trigger {
    public:
        AreaTrigger(const Components::Area &area) : m_area(area) {}

    protected:
        Components::Area m_area;
    };
}

#endif //FLASH_AREATRIGGER_H
