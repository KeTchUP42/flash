//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_SELFACTIONABLE_H
#define FLASH_SELFACTIONABLE_H

namespace Possibilities {

    /**
     * @brief The base class of the SelfActionable class hierarchy.
     * @namespace Possibilities
     *
     * This class defines base SelfActionable interface.
    */
    template<class Unifier>
    class SelfActionable {
    public:
        SelfActionable() = default;

        /**
         * @brief Method delegating all work to other "self" methods.
         */
        virtual void selfAction(Unifier *unifier) = 0;

        virtual ~SelfActionable() = default;
    };
}

#endif //FLASH_SELFACTIONABLE_H
