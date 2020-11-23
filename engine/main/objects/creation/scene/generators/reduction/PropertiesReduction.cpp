//
// Created by roman on 12.10.2020.
//

#include "PropertiesReduction.h"
#include "../../../../../../utils/math/algorithms.h"
#include "ElementaryReduction.h"

Mobs::MobProperties Creation::RD::loadMobProperties(const IniUtil::Analyzer::IniBlock &data) {
    return Mobs::MobProperties(speed(data, "SPEED"), std::atof(data.at("MAX_HEALTH_POINTS").c_str()), std::atof(data.at("HEALTH_POINTS").c_str()));
}

Obstacles::ObstacleProperties Creation::RD::loadObstacleProperties(const IniUtil::Analyzer::IniBlock &data) {
    float elasticCoefficient = std::stof(data.at("ELASTIC_COEFFICIENT"));
    float frictionCoefficient = std::stof(data.at("FRICTION_COEFFICIENT"));
    bool isFixed = std::atoi(data.at("IS_FIXED").c_str());
    return Obstacles::ObstacleProperties(speed(data, "SPEED"), elasticCoefficient, frictionCoefficient, isFixed);
}
