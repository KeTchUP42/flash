//
// Created by roman on 18.09.2020.
//

#include "CoordinatesCalculation.h"

#include <algorithm>

Components::Point Material::maxCoordinates(const Possibilities::PhysicallySituated &object) noexcept {
    float maxX = std::max_element(
            object.getCoordinates().list.begin(), object.getCoordinates().list.end(),
            [](const Components::Point &point1, const Components::Point &point2) {
                return point1.x < point2.x;
            })->x;

    float maxY = std::max_element(
            object.getCoordinates().list.begin(), object.getCoordinates().list.end(),
            [](const Components::Point &point1, const Components::Point &point2) {
                return point1.y < point2.y;
            })->y;
    return Components::Point(maxX, maxY);
}

Components::Point Material::minCoordinates(const Possibilities::PhysicallySituated &object) noexcept {
    float minX = std::min_element(
            object.getCoordinates().list.begin(), object.getCoordinates().list.end(),
            [](const Components::Point &point1, const Components::Point &point2) {
                return point1.x < point2.x;
            })->x;

    float minY = std::min_element(
            object.getCoordinates().list.begin(), object.getCoordinates().list.end(),
            [](const Components::Point &point1, const Components::Point &point2) {
                return point1.y < point2.y;
            })->y;
    return Components::Point(minX, minY);
}
