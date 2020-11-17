//
// Created by roman on 10.11.2020.
//

#include "ImpactPlayerZone.h"

Triggers::ImpactPlayerZone::ImpactPlayerZone(const Components::Area &area, Triggers::Handler<Mobs::Player> *handler) : ImpactZone(area, handler) {}

Triggers::ResultCodes Triggers::ImpactPlayerZone::verifyTrigger(Unite::Unifier *unifier) noexcept {
    for (Mobs::Player *player: unifier->getPlayers()) {

        if (Material::OptimizedCollision<Possibilities::MaterialRectangle, Mobs::Player>(*this, *player)) {
            m_handler->handle(*player);
        }
    }
    return ResultCodes::OK;
}
