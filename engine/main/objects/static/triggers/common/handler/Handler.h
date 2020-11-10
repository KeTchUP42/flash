//
// Created by roman on 04.10.2020.
//

#ifndef FLASH_HANDLER_H
#define FLASH_HANDLER_H

namespace Triggers {

    /**
     * @brief The base class of the Handler class hierarchy. Uses for change objects state.
     * @namespace Triggers
     *
     * This class defines base Handler interface.
    */
    template<class Type>
    class Handler {
    public:
        Handler() = default;

        /**
         * @brief Method handles object before trigger action.
         * @param object Object.
         */
        virtual void handle(Type &object) const noexcept = 0;

        virtual ~Handler() = default;
    };
}

#endif //FLASH_HANDLER_H
