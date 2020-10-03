//
// Created by roman on 26.09.2020.
//

#include "ExplicitPlayerSceneTrigger.h"
#include "../../../unifier/GeneralUnifier.h"
#include "../../../../view/windows/screen/states/TransitScreenState.h"
#include "../../../../../utils/math/Rectangle.h"

Triggers::ExplicitPlayerSceneTrigger::ExplicitPlayerSceneTrigger(const std::string &filename, const Components::Area &area,
                                                                 const Components::Point &target, Screen::StateChangeable *context)
        : SceneTrigger(filename, area, context), m_target(target) {}


Triggers::ResultCodes Triggers::ExplicitPlayerSceneTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {
    for (const std::shared_ptr<Mobs::Player> &player: unifier->getPlayers()) {

        if (MathUtils::collision(m_area, *player)) {

            Unite::Unifier *new_unifier = new Unite::GeneralUnifier();
            for (const std::shared_ptr<Mobs::Player> &plr: unifier->getPlayers()) {
                plr->setPosition(m_target);
                new_unifier->addPlayer(plr);
            }

            m_context->setScreenState(new Screen::TransitScreenState(m_sceneFileName, new_unifier));
            return ResultCodes::STOP;
        }
    }
    return ResultCodes::OK;
}
