//
// Created by roman on 26.09.2020.
//

#include "PlainSceneTrigger.h"
#include "../../../unifier/GeneralUnifier.h"
#include "../../../../view/windows/screen/states/TransitScreenState.h"

Triggers::PlainSceneTrigger::PlainSceneTrigger(const std::string &filename, const Components::Area &area,
                                               Screen::StateChangeable *context)
        : SceneTrigger(filename, area, context) {}


Triggers::ResultCodes Triggers::PlainSceneTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {
    for (const std::shared_ptr<Mobs::Player> &plyr: unifier->getPlayers()) {

        float playerX = plyr->getPosition().x;
        float playerY = plyr->getPosition().y;
        unsigned playerWidth = plyr->getSize().width;
        unsigned playerHeight = plyr->getSize().height;

        if (((playerX > m_area.point.x) && (playerX <= m_area.point.x + m_area.size.width) &&
             (plyr->getPosition().y > m_area.point.y) && (plyr->getPosition().y <= m_area.point.y + m_area.size.height)) ||
            ((playerX + playerWidth > m_area.point.x) && (playerX + playerWidth <= m_area.point.x + m_area.size.width) &&
             (playerY + playerHeight > m_area.point.y) && (playerY + playerHeight <= m_area.point.y + m_area.size.height))) {

            std::shared_ptr<Unite::Unifier> new_unifier(new Unite::GeneralUnifier());
            for (const std::shared_ptr<Mobs::Player> &player: unifier->getPlayers()) {
                new_unifier->addPlayer(player);
            }

            m_context->setScreenState(new Screen::TransitScreenState(m_scene_filename, new_unifier));
            return ResultCodes::STOP;
        }
    }
    return ResultCodes::OK;
}
