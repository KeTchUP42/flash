//
// Created by roman on 02.11.2020.
//

#include "CommonCollisionAlgorithms.h"

/**
 * @brief This is help function for collision function.
 * @return The value responsible for the position of the point relative to the vector.
 */
static inline bool product(float x, float y, const Components::Point &current, const Components::Point &next) {
    return ((next.x - current.x) * (y - current.y) - (next.y - current.y) * (x - current.x)) >= 0;
}

bool Material::collision(float x, float y, const Possibilities::PhysicallySituated &object) noexcept {
    if (object.getCoordinates().list.size() < 3) return false;

    bool result = true;
    for (size_t i = 0; i < object.getCoordinates().list.size() - 1; ++i) {
        result = result && product(x, y, object.getCoordinates().list[i], object.getCoordinates().list[i + 1]);
    }

    result = result && product(x, y, object.getCoordinates().list[object.getCoordinates().list.size() - 1], object.getCoordinates().list[0]);
    return result;
}

bool Material::collision(const Possibilities::PhysicallySituated &object1, const Possibilities::PhysicallySituated &object2) noexcept {
    for (const Components::Point &point : object2.getCoordinates().list) {
        if (collision(point.x, point.y, object1)) return true;
    }

    for (const Components::Point &point : object1.getCoordinates().list) {
        if (collision(point.x, point.y, object2)) return true;
    }
    return false;
}

