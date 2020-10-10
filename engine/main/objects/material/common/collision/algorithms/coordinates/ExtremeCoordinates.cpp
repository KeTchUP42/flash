//
// Created by roman on 21.09.2020.
//

#include "ExtremeCoordinates.h"

std::vector<Components::Point>
Material::extremeCoordinatesAbscissa(const Material::MaterialObject &object, float absentXValue) noexcept {
    std::vector<Components::Point> result;
    if (object.getCoordinates().point_1.x != absentXValue) {
        result.push_back(object.getCoordinates().point_1);
    }

    if (object.getCoordinates().point_2.x != absentXValue) {
        result.push_back(object.getCoordinates().point_2);
    }

    if (object.getCoordinates().point_3.x != absentXValue) {
        result.push_back(object.getCoordinates().point_3);
    }

    if (object.getCoordinates().point_4.x != absentXValue) {
        result.push_back(object.getCoordinates().point_4);
    }

    return result;
}

std::vector<Components::Point>
Material::extremeCoordinatesOrdinate(const Material::MaterialObject &object, float absentYValue) noexcept {
    std::vector<Components::Point> result;
    if (object.getCoordinates().point_1.y != absentYValue) {
        result.push_back(object.getCoordinates().point_1);
    }

    if (object.getCoordinates().point_2.y != absentYValue) {
        result.push_back(object.getCoordinates().point_2);
    }

    if (object.getCoordinates().point_3.y != absentYValue) {
        result.push_back(object.getCoordinates().point_3);
    }

    if (object.getCoordinates().point_4.y != absentYValue) {
        result.push_back(object.getCoordinates().point_4);
    }

    return result;
}