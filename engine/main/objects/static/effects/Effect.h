//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_EFFECT_H
#define FLASH_EFFECT_H

namespace Unite {
    class Unifier;
}

namespace Effects {

    /**
     * @brief The base class of the Effect class hierarchy.
     * @namespace Effects
     *
     * This class defines base Effect interface.
    */
    class Effect {
    public:
        Effect() = default;

        /**
         * @brief Method applies needed effect.
         * @param unifier Screen objects unifier.
         */
        virtual void applyEffect(Unite::Unifier *unifier) = 0;

        virtual ~Effect() = default;
    };
}

#include "../../unifier/common/Unifier.h"

#endif //FLASH_EFFECT_H
