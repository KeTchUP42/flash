//
// Created by roman on 12.10.2020.
//

#include "PropertiesReduction.h"
#include "ElementaryReduction.h"

Material::MaterialProperties Creation::RD::loadMaterialProperties(const IniUtil::Analyzer::IniBlock &data) {
    return Material::MaterialProperties(RD::speed(data, "SPEED"));
}

Mobs::MobProperties Creation::RD::loadMobProperties(const IniUtil::Analyzer::IniBlock &data) {
    return Mobs::MobProperties(std::stof(data.at("MAX_HEALTH_POINTS").c_str()), std::stof(data.at("HEALTH_POINTS").c_str()));
}

Obstacles::ObstacleProperties Creation::RD::loadObstacleProperties(const IniUtil::Analyzer::IniBlock &data) {
    float elasticCoefficient = std::stof(data.at("ELASTIC_COEFFICIENT"));
    float frictionCoefficient = std::stof(data.at("FRICTION_COEFFICIENT"));
    bool isFixed = static_cast<bool>(std::atoi(data.at("IS_FIXED").c_str()));
    return Obstacles::ObstacleProperties(elasticCoefficient, frictionCoefficient, isFixed);
}
