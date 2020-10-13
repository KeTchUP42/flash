//
// Created by roman on 12.10.2020.
//

#include "PropertiesReduction.h"

Obstacles::ObstacleProperties Generate::loadObstacleProperties(const IniUtil::Analyzer::IniBlock &data) noexcept {
    Components::Speed speed(std::stof(data.at("X_SPEED")), std::stof(data.at("Y_SPEED")));
    float elasticCoefficient = std::stof(data.at("ELASTIC_COEFFICIENT"));
    float frictionCoefficient = std::stof(data.at("FRICTION_COEFFICIENT"));
    bool isFixed = std::atoi(data.at("IS_FIXED").c_str());
    return Obstacles::ObstacleProperties(speed, elasticCoefficient, frictionCoefficient, isFixed);
}
