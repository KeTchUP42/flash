//
// Created by roman on 07.10.2020.
//

#ifndef FLASH_MIND_H
#define FLASH_MIND_H

namespace Unite {
    class Unifier;
}

namespace Mobs {

    /**
     * @brief The base class of the Mind class hierarchy. Specific classes can be friends with the owner classes.
     * @namespace Mobs
     *
     * This class defines base Mind interface.
    */
    template<class Holder>
    class Mind {
    public:
        Mind(Holder *holder) : m_holder(holder) {}

        /**
         * @brief Main mind entry point method.
         * @param unifier System unifier.
         */
        virtual void analyze(Unite::Unifier *unifier) noexcept = 0;

    protected:
        Holder *m_holder;
    };
}

#include "../../../../unifier/common/Unifier.h"

#endif //FLASH_MIND_H
