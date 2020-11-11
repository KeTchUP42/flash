//
// Created by roman on 11.11.2020.
//

#include "DeathMobsHandler.h"

void Triggers::DeathMobsHandler::handle(Mobs::Mob &object) const noexcept {
    object.kill();
}
