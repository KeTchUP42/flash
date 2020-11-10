//
// Created by roman on 10.11.2020.
//

#include "ImpactPlayerTrigger.h"

Triggers::ImpactPlayerTrigger::ImpactPlayerTrigger(const Components::Area &area, Triggers::Handler<Mobs::Player> *handler) : ImpactTrigger(area, handler) {}

Triggers::ResultCodes Triggers::ImpactPlayerTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {
    for (const std::shared_ptr<Mobs::Player> &player: unifier->getPlayers()) {

        if (Material::OptimizedCollision<Possibilities::MaterialRectangle, Mobs::Player>(*this, *player)) {
            m_handler->handle(*player);
        }
    }
    return ResultCodes::OK;
}
