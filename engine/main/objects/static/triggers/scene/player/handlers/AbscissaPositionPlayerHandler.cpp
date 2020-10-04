//
// Created by roman on 04.10.2020.
//

#include "AbscissaPositionPlayerHandler.h"

Triggers::AbscissaPositionPlayerHandler::AbscissaPositionPlayerHandler(float abscissa) : m_abscissa(abscissa) {}

void Triggers::AbscissaPositionPlayerHandler::handle(Mobs::Player &object) const noexcept {
    object.setPosition(m_abscissa, object.getPosition().y);
}