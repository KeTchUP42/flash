//
// Created by roman on 14.11.2020.
//

#ifndef FLASH_GRAVITYHANDLER_H
#define FLASH_GRAVITYHANDLER_H

#include "../../common/handler/Handler.h"

namespace Triggers {

    template<class Type>
    class GravityHandler : public Handler<Type> {
    public:
        explicit GravityHandler(float accelerationX, float accelerationY)
                : X_ACCELERATION(accelerationX), Y_ACCELERATION(accelerationY) {}

        void handle(Type &object) const noexcept override {
            object.addSpeed(X_ACCELERATION, Y_ACCELERATION);
        }

    private:
        const float X_ACCELERATION;
        const float Y_ACCELERATION;
    };
}

#endif //FLASH_GRAVITYHANDLER_H
