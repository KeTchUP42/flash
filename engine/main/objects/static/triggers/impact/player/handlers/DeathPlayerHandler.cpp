//
// Created by roman on 10.11.2020.
//

#include "DeathPlayerHandler.h"

void Triggers::DeathPlayerHandler::handle(Mobs::Player &object) const noexcept {
    object.kill();
}
