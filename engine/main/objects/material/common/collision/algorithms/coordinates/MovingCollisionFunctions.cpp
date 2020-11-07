//
// Created by roman on 03.11.2020.
//

#include "MovingCollisionFunctions.h"

static std::pair<float, float>
ordinateVergeIndex(const Possibilities::PhysicallySituated &object, const std::pair<float, float> &ordinateVerge, bool moveSide) noexcept {
    std::pair<float, float> result(0, 0);
    Components::Point curentMinY = object.getCoordinates().list.at(0);
    Components::Point curentMaxY = object.getCoordinates().list.at(0);

    for (size_t i = 0; i < object.getCoordinates().list.size(); ++i) {

        if (((curentMinY.y != ordinateVerge.first) && (object.getCoordinates().list[i].y == ordinateVerge.first)) ||
            ((object.getCoordinates().list[i].y == ordinateVerge.first) &&
             ((moveSide) ? object.getCoordinates().list[i].x > curentMinY.x : object.getCoordinates().list[i].x < curentMinY.x))) {
            result.first = i;
            curentMinY = object.getCoordinates().list[i];
            continue;
        }

        if (((curentMaxY.y != ordinateVerge.second) && (object.getCoordinates().list[i].y == ordinateVerge.second)) ||
            ((object.getCoordinates().list[i].y == ordinateVerge.second) &&
             ((moveSide) ? object.getCoordinates().list[i].x > curentMaxY.x : object.getCoordinates().list[i].x < curentMaxY.x))) {
            result.second = i;
            curentMaxY = object.getCoordinates().list[i];
            continue;
        }
    }
    return result;
}

std::vector<Components::Point>
Material::pickoutNodulesVertical(const Possibilities::PhysicallySituated &object, const std::pair<float, float> &ordinateVerge, bool moveSide) noexcept {
    std::vector<Components::Point> pointsOffset;
    std::pair<float, float> ordinateVergePoints = ordinateVergeIndex(object, ordinateVerge, moveSide);
    pointsOffset.push_back(object.getCoordinates().list[ordinateVergePoints.first]);

    int index = ordinateVergePoints.first;
    short indexStep = moveSide ? 1 : -1; //If the points are set in a clockwise direction.

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
    Components::Point curentMinX = object.getCoordinates().list.at(0);
    Components::Point curentMaxX = object.getCoordinates().list.at(0);

    for (size_t i = 0; i < object.getCoordinates().list.size(); ++i) {

        if (((curentMinX.x != abscissaVerge.first) && (object.getCoordinates().list[i].x == abscissaVerge.first)) ||
            ((object.getCoordinates().list[i].x == abscissaVerge.first) &&
             ((moveSide) ? object.getCoordinates().list[i].y > curentMinX.y : object.getCoordinates().list[i].y < curentMinX.y))) {
            result.first = i;
            curentMinX = object.getCoordinates().list[i];
            continue;
        }

        if (((curentMaxX.x != abscissaVerge.second) && (object.getCoordinates().list[i].x == abscissaVerge.second)) ||
            ((object.getCoordinates().list[i].x == abscissaVerge.second) &&
             ((moveSide) ? object.getCoordinates().list[i].y > curentMaxX.y : object.getCoordinates().list[i].y < curentMaxX.y))) {
            result.second = i;
            curentMaxX = object.getCoordinates().list[i];
            continue;
        }
    }
    return result;
}

std::vector<Components::Point>
Material::pickoutNodulesHorizontal(const Possibilities::PhysicallySituated &object, const std::pair<float, float> &abscissaVerge, bool moveSide) noexcept {
    std::vector<Components::Point> pointsOffset;
    std::pair<float, float> abscissaVergePoints = abscissaVergeIndex(object, abscissaVerge, moveSide);
    pointsOffset.push_back(object.getCoordinates().list[abscissaVergePoints.first]);

    int index = abscissaVergePoints.first;
    short indexStep = moveSide ? -1 : 1; //If the points are set in a clockwise direction.

    while (index != abscissaVergePoints.second) {
        index += indexStep;
        if (index == -1) index = object.getCoordinates().list.size() - 1;
        if (index == object.getCoordinates().list.size()) index = 0;
        pointsOffset.push_back(object.getCoordinates().list[index]);
    }
    return pointsOffset;
}
