//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_GRAVITYEFFECT_H
#define FLASH_GRAVITYEFFECT_H

#include "../Effect.h"

namespace Effects {

    class GravityEffect : public Effect {
    public:
        /**
         * @brief Configures gravity power.
         */
        explicit GravityEffect(float accelerationX, float accelerationY);

        void applyEffect(Unite::Unifier *unifier) override;

    protected:
        const float X_ACCELERATION;
        const float Y_ACCELERATION;
    };
}

#endif //FLASH_GRAVITYEFFECT_H
