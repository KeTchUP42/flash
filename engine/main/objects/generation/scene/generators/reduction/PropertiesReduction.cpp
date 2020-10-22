//
// Created by roman on 12.10.2020.
//

#include "PropertiesReduction.h"
#include "../../../../../../utils/math/algorithms.h"
#include "ElementaryReduction.h"

Mobs::MobProperties Generate::loadMobProperties(const IniUtil::Analyzer::IniBlock &data) {
    return Mobs::MobProperties(std::atof(data.at("HEALTH_POINTS").c_str()), speed(data, "SPEED"));
}

Obstacles::ObstacleProperties Generate::loadObstacleProperties(const IniUtil::Analyzer::IniBlock &data) {
    float elasticCoefficient = std::stof(data.at("ELASTIC_COEFFICIENT"));
    float frictionCoefficient = std::stof(data.at("FRICTION_COEFFICIENT"));
    bool isFixed = std::atoi(data.at("IS_FIXED").c_str());
    return Obstacles::ObstacleProperties(speed(data, "SPEED"), elasticCoefficient, frictionCoefficient, isFixed);
}
