//
// Created by roman on 04.10.2020.
//

#include "OrdinatePositionPlayerHandler.h"

Triggers::OrdinatePositionPlayerHandler::OrdinatePositionPlayerHandler(float ordinate) : m_ordinate(ordinate) {}

void Triggers::OrdinatePositionPlayerHandler::handle(Mobs::Player &object) const noexcept {
    object.setPosition(object.getPosition().x, m_ordinate);
}
