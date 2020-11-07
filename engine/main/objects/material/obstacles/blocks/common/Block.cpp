//
// Created by roman on 02.11.2020.
//

#include "Block.h"
#include "../../../../../../utils/math/rectangle.h"

void Obstacles::Block::updateCoordinates() noexcept {
    //TODO Coordinates are not updated if you turn the real estate object.
    //Some optimization logic. Can be changed with general movement logic update.
    if (!((this->getSpeed().xSpeed == 0) && (this->getSpeed().ySpeed == 0))) {
        m_coordinates = MathUtils::coordinates(this);
    } else if (m_coordinates.list.empty()) {
        m_coordinates = MathUtils::coordinates(this);
    }
}
