//
// Created by roman on 04.10.2020.
//

#include "PlayerSceneTrigger.h"
#include "../../../../unifier/SceneUnifier.h"
#include "../../../../../view/windows/screen/states/TransitScreenState.h"

Triggers::PlayerSceneTrigger::PlayerSceneTrigger(const std::string &filename, const Components::Area &area,
                                                 Handler<Mobs::Player> *handler, View::StateChangeable *context)
        : SceneTrigger(filename, area, context), m_handler(handler) {}

Triggers::ResultCodes Triggers::PlayerSceneTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {
    for (const std::shared_ptr<Mobs::Player> &player: unifier->getPlayers()) {

        if (Material::RectangleCollision<Possibilities::MaterialRectangle, Mobs::Player>(*this, *player)) {

            Unite::Unifier *new_unifier = new Unite::SceneUnifier();
            for (const std::shared_ptr<Mobs::Player> &plr: unifier->getPlayers()) {
                m_handler->handle(*plr);
                new_unifier->addPlayer(plr);
            }

            m_context->setScreenState(new View::TransitScreenState(m_scene_file, new_unifier));
            return ResultCodes::STOP;
        }
    }
    return ResultCodes::OK;
}
