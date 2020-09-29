//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_TRIGGER_H
#define FLASH_TRIGGER_H

#include "../../unifier/common/Unifier.h"
#include "../../../view/windows/base/observer/Observer.h"
#include "codes/ResultCodes.h"

namespace Triggers {

    /**
     * @brief The base class of the Trigger class hierarchy.
     * @namespace Triggers
     *
     * This class defines base Trigger interface.
    */
    class Trigger : public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        /**
         * @brief Triggers must get StateChangeable pointer.
         */
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
