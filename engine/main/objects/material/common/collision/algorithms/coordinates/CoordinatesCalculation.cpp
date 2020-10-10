//
// Created by roman on 18.09.2020.
//

#include "CoordinatesCalculation.h"

#include <algorithm>

Components::Point Material::maxCoordinates(const Material::MaterialObject &object) noexcept {
    return Components::Point(std::max(std::max(object.getCoordinates().point_2.x, object.getCoordinates().point_3.x), std::max(object.getCoordinates().point_4.x, object.getCoordinates().point_1.x)),
                             std::max(std::max(object.getCoordinates().point_2.y, object.getCoordinates().point_3.y), std::max(object.getCoordinates().point_4.y, object.getCoordinates().point_1.y)));
}

Components::Point Material::minCoordinates(const Material::MaterialObject &object) noexcept {
    return Components::Point(std::min(std::min(object.getCoordinates().point_2.x, object.getCoordinates().point_3.x), std::min(object.getCoordinates().point_4.x, object.getCoordinates().point_1.x)),
                             std::min(std::min(object.getCoordinates().point_2.y, object.getCoordinates().point_3.y), std::min(object.getCoordinates().point_4.y, object.getCoordinates().point_1.y)));
}
