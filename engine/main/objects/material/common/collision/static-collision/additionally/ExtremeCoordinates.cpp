//
// Created by roman on 21.09.2020.
//

#include "ExtremeCoordinates.h"

std::vector<Components::Point>
Material::extremeCoordinatesAbscissa(const Possibilities::RectangleGetters &rectangle, float absentXValue) noexcept {
    std::vector<Components::Point> result;
    OtherUtils::RectangleCoordinates coordinates = OtherUtils::coordinates(rectangle);

    if (coordinates.point_1.x != absentXValue) {
        result.push_back(coordinates.point_1);
    }

    if (coordinates.point_2.x != absentXValue) {
        result.push_back(coordinates.point_2);
    }

    if (coordinates.point_3.x != absentXValue) {
        result.push_back(coordinates.point_3);
    }

    if (coordinates.point_4.x != absentXValue) {
        result.push_back(coordinates.point_4);
    }

    return std::move(result);
}

std::vector<Components::Point>
Material::extremeCoordinatesOrdinate(const Possibilities::RectangleGetters &rectangle, float absentYValue) noexcept {
    std::vector<Components::Point> result;
    OtherUtils::RectangleCoordinates coordinates = OtherUtils::coordinates(rectangle);

    if (coordinates.point_1.y != absentYValue) {
        result.push_back(coordinates.point_1);
    }

    if (coordinates.point_2.y != absentYValue) {
        result.push_back(coordinates.point_2);
    }

    if (coordinates.point_3.y != absentYValue) {
        result.push_back(coordinates.point_3);
    }

    if (coordinates.point_4.y != absentYValue) {
        result.push_back(coordinates.point_4);
    }

    return std::move(result);
}