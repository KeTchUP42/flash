//
// Created by roman on 12.10.2020.
//

#include "PropertiesReduction.h"
#include "../../../../../../utils/math/algorithms.h"
#include "ElementaryReduction.h"

Mobs::MonsterProperties Generate::loadMonsterProperties(const IniUtil::Analyzer::IniBlock &data) {
    return Mobs::MonsterProperties(speed(data, "SPEED"));
}

Mobs::PlayerProperties Generate::loadPlayerProperties(const IniUtil::Analyzer::IniBlock &data) {
    return Mobs::PlayerProperties(speed(data, "SPEED"));
}

Obstacles::ObstacleProperties Generate::loadObstacleProperties(const IniUtil::Analyzer::IniBlock &data) {
    float elasticCoefficient = std::stof(data.at("ELASTIC_COEFFICIENT"));
    float frictionCoefficient = std::stof(data.at("FRICTION_COEFFICIENT"));
    bool isFixed = std::atoi(data.at("IS_FIXED").c_str());
    return Obstacles::ObstacleProperties(speed(data, "SPEED"), elasticCoefficient, frictionCoefficient, isFixed);
}
