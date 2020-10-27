//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_TRIGGER_H
#define FLASH_TRIGGER_H

#include "../../../../view/windows/base/observer/Observer.h"
#include "../../../unifier/common/Unifier.h"
#include "codes/ResultCodes.h"

namespace Triggers {

    /**
     * @brief The base class of the Trigger class hierarchy.
     * @namespace Triggers
     *
     * This class defines base Trigger interface.
    */
    class Trigger : public View::Observer<sf::Event, View::Window> {
    public:
        Trigger() = default;

        /**
         * @brief Method checks trigger's conditions.
         * @param unifier Level unifier.
         */
        virtual ResultCodes verifyTrigger(Unite::Unifier *unifier) noexcept = 0;

        virtual ~Trigger() = default;
    };
}

#endif //FLASH_TRIGGER_H
