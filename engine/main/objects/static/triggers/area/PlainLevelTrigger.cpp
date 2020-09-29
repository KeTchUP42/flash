//
// Created by roman on 26.09.2020.
//

#include "PlainLevelTrigger.h"
#include "../../../unifier/GeneralUnifier.h"
#include "../../../../view/windows/screen/states/TransitScreenState.h"

Triggers::PlainLevelTrigger::PlainLevelTrigger(const Components::Area &area, Screen::StateChangeable *context)
        : AreaTrigger(area), m_context(context) {}

Triggers::ResultCodes Triggers::PlainLevelTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {
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

            m_context->setScreenState(new Screen::TransitScreenState("", new_unifier));
            //todo: Fix Triggers. Make new base "new Level" trigger class.
            return ResultCodes::STOP;
        }
    }
    return ResultCodes::OK;
}

void Triggers::PlainLevelTrigger::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}
