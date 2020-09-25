//
// Created by roman on 25.09.2020.
//

#include "MaterialProperties.h"

Material::MaterialProperties::MaterialProperties(const Components::Speed &speed, float elasticCoefficient)
        : speed(speed), elasticCoefficient(elasticCoefficient) {}
