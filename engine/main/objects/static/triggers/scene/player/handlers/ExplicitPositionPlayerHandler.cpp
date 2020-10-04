//
// Created by roman on 04.10.2020.
//

#include "ExplicitPositionPlayerHandler.h"

Triggers::ExplicitPositionPlayerHandler::ExplicitPositionPlayerHandler(const Components::Point &target) : m_target(target) {}

void Triggers::ExplicitPositionPlayerHandler::handle(Mobs::Player &object) const noexcept {
    object.setPosition(m_target);
}
