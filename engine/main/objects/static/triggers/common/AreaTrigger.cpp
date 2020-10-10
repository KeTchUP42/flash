//
// Created by roman on 10.10.2020.
//

#include "AreaTrigger.h"

const Components::Coordinates &Triggers::AreaTrigger::getCoordinates() const noexcept {
    return m_coordinates;
}

const Components::Point &Triggers::AreaTrigger::getPosition() const noexcept {
    return m_area.m_point;
}

const Components::Size &Triggers::AreaTrigger::getSize() const noexcept {
    return m_area.m_size;
}

float Triggers::AreaTrigger::getRotation() const noexcept {
    return m_area.m_angle;
}
