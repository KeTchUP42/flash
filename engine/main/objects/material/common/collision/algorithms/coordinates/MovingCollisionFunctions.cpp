//
// Created by roman on 03.11.2020.
//

#include "MovingCollisionFunctions.h"

static std::pair<float, float>
ordinateVergeIndex(const Possibilities::PhysicallySituated &object, const std::pair<float, float> &ordinateVerge, bool moveSide) noexcept {
    std::pair<float, float> result(0, 0);
    Components::Point currentMinY = object.getCoordinates().list.at(0);
    Components::Point currentMaxY = object.getCoordinates().list.at(0);

    for (size_t i = 0; i < object.getCoordinates().list.size(); ++i) {

        if (((currentMinY.y != ordinateVerge.first) && (object.getCoordinates().list[i].y == ordinateVerge.first)) ||
            ((object.getCoordinates().list[i].y == ordinateVerge.first) &&
             ((moveSide) ? object.getCoordinates().list[i].x > currentMinY.x : object.getCoordinates().list[i].x < currentMinY.x))) {
            result.first = i;
            currentMinY = object.getCoordinates().list[i];
            continue;
        }

        if (((currentMaxY.y != ordinateVerge.second) && (object.getCoordinates().list[i].y == ordinateVerge.second)) ||
            ((object.getCoordinates().list[i].y == ordinateVerge.second) &&
             ((moveSide) ? object.getCoordinates().list[i].x > currentMaxY.x : object.getCoordinates().list[i].x < currentMaxY.x))) {
            result.second = i;
            currentMaxY = object.getCoordinates().list[i];
            continue;
        }
    }
    return result;
}

std::vector<Components::Point>
Material::pickoutNodesVertical(const Possibilities::PhysicallySituated &object, const std::pair<float, float> &ordinateVerge, bool moveSide) noexcept {
    std::vector<Components::Point> pointsOffset;
    std::pair<float, float> ordinateVergePoints = ordinateVergeIndex(object, ordinateVerge, moveSide);
    pointsOffset.push_back(object.getCoordinates().list[ordinateVergePoints.first]);

    int index = ordinateVergePoints.first;
    short indexStep = moveSide ? 1 : -1; //Makes sense if the coordinates go around in a clockwise direction.

    while (index != ordinateVergePoints.second) {
        index += indexStep;
        if (index == -1) index = object.getCoordinates().list.size() - 1;
        if (index == object.getCoordinates().list.size()) index = 0;
        pointsOffset.push_back(object.getCoordinates().list[index]);
    }
    return pointsOffset;
}

static std::pair<float, float>
abscissaVergeIndex(const Possibilities::PhysicallySituated &object, const std::pair<float, float> &abscissaVerge, bool moveSide) noexcept {
    std::pair<float, float> result(0, 0);
    Components::Point currentMinX = object.getCoordinates().list.at(0);
    Components::Point currentMaxX = object.getCoordinates().list.at(0);

    for (size_t i = 0; i < object.getCoordinates().list.size(); ++i) {

        if (((currentMinX.x != abscissaVerge.first) && (object.getCoordinates().list[i].x == abscissaVerge.first)) ||
            ((object.getCoordinates().list[i].x == abscissaVerge.first) &&
             ((moveSide) ? object.getCoordinates().list[i].y > currentMinX.y : object.getCoordinates().list[i].y < currentMinX.y))) {
            result.first = i;
            currentMinX = object.getCoordinates().list[i];
            continue;
        }

        if (((currentMaxX.x != abscissaVerge.second) && (object.getCoordinates().list[i].x == abscissaVerge.second)) ||
            ((object.getCoordinates().list[i].x == abscissaVerge.second) &&
             ((moveSide) ? object.getCoordinates().list[i].y > currentMaxX.y : object.getCoordinates().list[i].y < currentMaxX.y))) {
            result.second = i;
            currentMaxX = object.getCoordinates().list[i];
            continue;
        }
    }
    return result;
}

std::vector<Components::Point>
Material::pickoutNodesHorizontal(const Possibilities::PhysicallySituated &object, const std::pair<float, float> &abscissaVerge, bool moveSide) noexcept {
    std::vector<Components::Point> pointsOffset;
    std::pair<float, float> abscissaVergePoints = abscissaVergeIndex(object, abscissaVerge, moveSide);
    pointsOffset.push_back(object.getCoordinates().list[abscissaVergePoints.first]);

    int index = abscissaVergePoints.first;
    short indexStep = moveSide ? -1 : 1; //Makes sense if the coordinates go around in a clockwise direction.

    while (index != abscissaVergePoints.second) {
        index += indexStep;
        if (index == -1) index = object.getCoordinates().list.size() - 1;
        if (index == object.getCoordinates().list.size()) index = 0;
        pointsOffset.push_back(object.getCoordinates().list[index]);
    }
    return pointsOffset;
}
