//
// Created by roman on 18.09.2020.
//

#include "CoordinatesCalculation.h"
#include "../../../../../../../utils/math/Rectangle.h"

#include <algorithm>

Components::Point Material::maxCoordinates(const Possibilities::RectangleGetters &rectangle) noexcept {
    MathUtils::RectangleCoordinates coordinates = MathUtils::coordinates(rectangle);
    return Components::Point(std::max(std::max(coordinates.point_2.x, coordinates.point_3.x), std::max(coordinates.point_4.x, coordinates.point_1.x)),
                             std::max(std::max(coordinates.point_2.y, coordinates.point_3.y), std::max(coordinates.point_4.y, coordinates.point_1.y)));
}

Components::Point Material::minCoordinates(const Possibilities::RectangleGetters &rectangle) noexcept {
    MathUtils::RectangleCoordinates coordinates = MathUtils::coordinates(rectangle);
    return Components::Point(std::min(std::min(coordinates.point_2.x, coordinates.point_3.x), std::min(coordinates.point_4.x, coordinates.point_1.x)),
                             std::min(std::min(coordinates.point_2.y, coordinates.point_3.y), std::min(coordinates.point_4.y, coordinates.point_1.y)));
}
