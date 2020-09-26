//
// Created by roman on 25.09.2020.
//

#ifndef FLASH_AREATRIGGER_H
#define FLASH_AREATRIGGER_H

#include "../Trigger.h"
#include "../../../auxiliary/components/elementary/area/Area.h"

namespace Triggers {

    /**
     * @brief The base class of the AreaTrigger class hierarchy. Base interface class for area triggers.
     * @namespace Triggers
     *
     * This class defines base AreaTrigger interface.
    */
    class AreaTrigger : public Trigger {
    public:
        AreaTrigger(const Components::Area &area) : _area(area) {}

    protected:
        Components::Area _area;
    };
}

#endif //FLASH_AREATRIGGER_H
