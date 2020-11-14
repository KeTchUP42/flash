//
// Created by roman on 14.11.2020.
//

#ifndef FLASH_DEATHHANDLER_H
#define FLASH_DEATHHANDLER_H

#include "../../common/handler/Handler.h"

namespace Triggers {

    template<class Type>
    class DeathHandler : public Handler<Type> {
    public:
        void handle(Type &object) const noexcept override {
            object.kill();
        }
    };
}

#endif //FLASH_DEATHHANDLER_H
