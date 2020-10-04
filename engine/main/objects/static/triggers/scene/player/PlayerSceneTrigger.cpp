//
// Created by roman on 04.10.2020.
//

#include "PlayerSceneTrigger.h"
#include "../../../../../../utils/math/Rectangle.h"
#include "../../../../unifier/GeneralUnifier.h"
#include "../../../../../view/windows/screen/states/TransitScreenState.h"

Triggers::PlayerSceneTrigger::PlayerSceneTrigger(const std::string &filename, const Components::Area &area,
                                                 Handler<Mobs::Player> *handler, Screen::StateChangeable *context)
        : SceneTrigger(filename, area, context), m_handler(handler) {}

Triggers::ResultCodes Triggers::PlayerSceneTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {
    for (const std::shared_ptr<Mobs::Player> &player: unifier->getPlayers()) {

        if (MathUtils::collision(m_area, *player)) {

            Unite::Unifier *new_unifier = new Unite::GeneralUnifier();
            for (const std::shared_ptr<Mobs::Player> &plr: unifier->getPlayers()) {
                m_handler->handle(*plr);
                new_unifier->addPlayer(plr);
            }

            m_context->setScreenState(new Screen::TransitScreenState(m_SceneFileName, new_unifier));
            return ResultCodes::STOP;
        }
    }
    return ResultCodes::OK;
}
