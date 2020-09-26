//
// Created by roman on 26.09.2020.
//

#include "PlainLevelTrigger.h"
#include "../../../unifier/GeneralUnifier.h"
#include "../../../../view/windows/screen/states/TransitScreenState.h"

Triggers::PlainLevelTrigger::PlainLevelTrigger(const Components::Area &area, Screen::StateChangeable *context)
        : AreaTrigger(area), _context(context) {}

Triggers::ResultCode Triggers::PlainLevelTrigger::verifyTrigger(Unite::Unifier *unifier) noexcept {
    for (const std::shared_ptr<Mobs::Player> &plyr: unifier->getPlayers()) {

        float playerX = plyr->getPosition().x;
        float playerY = plyr->getPosition().y;
        unsigned playerWidth = plyr->getSize().width;
        unsigned playerHeight = plyr->getSize().height;

        if (((playerX > _area.point.x) && (playerX <= _area.point.x + _area.size.width) &&
             (plyr->getPosition().y > _area.point.y) && (plyr->getPosition().y <= _area.point.y + _area.size.height)) ||
            ((playerX + playerWidth > _area.point.x) && (playerX + playerWidth <= _area.point.x + _area.size.width) &&
             (playerY + playerHeight > _area.point.y) && (playerY + playerHeight <= _area.point.y + _area.size.height))) {

            std::shared_ptr<Unite::Unifier> new_unifier(new Unite::GeneralUnifier());
            for (const std::shared_ptr<Mobs::Player> &player: unifier->getPlayers()) {
                new_unifier->addPlayer(player);
            }

            _context->setScreenState(new Screen::TransitScreenState(new_unifier));
            return ResultCode::STOP;
        }
    }
    return ResultCode::OK;
}

void Triggers::PlainLevelTrigger::update(const sf::Event &event, sf::RenderWindow &sender) {
    //..
}
