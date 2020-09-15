//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_GRAVITYEFFECT_H
#define FLASH_GRAVITYEFFECT_H

#include "Effect.h"

namespace Effects {

    class GravityEffect : public Effect {
    public:
        /**
         * @brief Configures gravity power.
         */
        GravityEffect(float acceleration);

        void applyEffect(Unite::Unifier *unifier) override;

    protected:
        const float ACCELERATION;
    };
}

#endif //FLASH_GRAVITYEFFECT_H
