//
// Created by roman on 11.11.2020.
//

#include "ImpactMobsZone.h"

Triggers::ImpactMobsZone::ImpactMobsZone(const Components::Area &area, Triggers::Handler<Mobs::Mob> *handler) : ImpactZone(area, handler) {}

Triggers::ResultCodes Triggers::ImpactMobsZone::verifyTrigger(Unite::Unifier *unifier) noexcept {
    for (const std::shared_ptr<Mobs::Mob> &mob: unifier->getMobs()) {

        if (Material::OptimizedCollision<Possibilities::MaterialRectangle, Mobs::Mob>(*this, *mob)) {
            m_handler->handle(*mob);
        }
    }
    return ResultCodes::OK;
}
